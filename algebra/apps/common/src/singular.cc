#include "polymake/client.h"
#include "polymake/common/singular.h"
#include "polymake/ListMatrix.h"
#include "polymake/Map.h"
#include "polymake/Ring.h"

#include <libsingular.h>


namespace polymake { namespace common {

int singular_initialized = 0;

Map<Ring<>::id_type, ring> singular_ring_map;

void singular_error_handler(const char* error)
{
   throw std::runtime_error(error);
}

void init_singular(const std::string& path) 
{
   if(singular_initialized)
   {
      cout << "Singular has already been initialized, restart polymake to retry" << endl;
      return;
   }
   
   std::string p = path+"/Singular/libsingular.so";
   char* cpath = omStrDup(p.c_str());
   siInit(cpath);
   WerrorS_callback = &singular_error_handler;
   
   cout << "init_singular done" << endl;
   singular_initialized = 1;
}

ring check_ring(Ring<> r){
	Ring<>::id_type id = r.id();
	if(!singular_ring_map.exists(id)){
      int nvars = r.n_vars();
      if(nvars == 0) 
         throw std::runtime_error("Given ring is not a polynomial ring.");
      char **n=(char**)omalloc(nvars*sizeof(char*));
      for(int i=0; i<nvars; i++)
      {
         n[i] = omStrDup(r.names()[i].c_str());
      }
      singular_ring_map[id] = rDefault(0,nvars,n);
	}
	return singular_ring_map[id];
}

Rational convert_number_to_Rational(number n, ring ring)
{
   if(rField_is_Q(ring)){
		if(SR_HDL(n) & SR_INT){
			long l = SR_TO_INT(n);
			return Rational(l, 1);
		} else {
			switch(n->s){
				case 0:
					return Rational(n->z, n->n);
				case 1:
					return Rational(n->z, n->n);
				case 3:
					return Rational(n->z);
			}
		}
	}
  	throw std::runtime_error("I can has number? :P");
}

number convert_Rational_to_number(const Rational& r)
{
   mpz_t num, denom;
   mpz_init(num);
   mpz_set(num,numerator(r).get_rep());
   mpz_init(denom);
   mpz_set(denom,denominator(r).get_rep());

   return nlInit2gmp(num,denom);
}

class SingularIdeal_impl : public SingularIdeal_wrap {
private:
   ideal singIdeal;

	// Send Polymake ideal to Singular
public:
   /*SingularIdeal_impl() 
   {
      if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating empty SingularIdeal_impl" << endl;
      singIdeal=NULL;
   }*/
   
   SingularIdeal_impl(const Array<Polynomial<> > gens) 
   {
		if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating SingularIdeal_impl from Ideal" << endl;
      
		ring singRing = check_ring(gens[0].get_ring());
      int npoly = gens.size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      rChangeCurrRing(singRing);

      singIdeal = idInit(npoly,1); // Richtig?
      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(gens); !mypoly.at_end(); ++mypoly, ++j) {
         poly p = p_ISet(0,singRing);
         
         for(Entire<Polynomial<>::term_hash>::const_iterator term = entire(mypoly->get_terms()); !term.at_end(); ++term)
         {
            poly monomial = p_Init(singRing); // Geht das noch?
            p_SetCoeff(monomial,convert_Rational_to_number(term->second),singRing); // Geht das SetCoeff so?
            
            for(int k = 0; k<term->first.dim(); k++)
            {
               p_SetExp(monomial,k+1,term->first[k],singRing); // Hier war der Ring drinne, muss er wieder rein?
            }
            p_Setm(monomial,singRing); // Ring noetig?
            p = p_Add_q(p,monomial,singRing);
         }
         cout << "poly: " << p_String(p,singRing,singRing) << endl;
         singIdeal->m[j]=p_Copy(p,singRing);
      }
      cout << "DONE CREATING singular object" << endl;
   }

   SingularIdeal_impl(ideal i)
   {
      if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating SingularIdeal_impl from singular stuff" << endl;
      singIdeal=i;
   }

	~SingularIdeal_impl() 
   {
      cout << "SingularIdeal_impl cleaning up" <<endl;
      /*if(singRing!=NULL) {
         if(singIdeal!=NULL)
            id_Delete(&singIdeal,singRing);
         //rKill(singRing);
      }*/
      cout << "SingularIdeal_impl destroyed" << endl;
   }

	// Compute a groebner basis of a Polymake ideal using Singular
   void std(const Ring<> r) 
   {
		ring singRing = check_ring(r); 
      rChangeCurrRing(singRing);

      ideal res;
      res = kStd(singIdeal,NULL,testHomog,NULL);
      cout << "DONE COMPUTING std basis" << endl;
		id_Delete(&singIdeal,singRing);
		singIdeal = res;
//      throw std::runtime_error("created singIdeal");
      // check if singIdeal exists
      // set singulardefaultring
      // call groebner
      // create polymake ideal maybe with singRing and singIdeal
   }

   Array<Polynomial<> > polynomials(const Ring<> r) const
   {
		ring singRing = check_ring(r); 
      rChangeCurrRing(singRing);

      int numgen = IDELEMS(singIdeal);
      std::vector<Polynomial<> > polys;

		int n = rVar(singRing);
      for(int j = 0; j<numgen; j++) {
         if(singIdeal->m[j] != NULL){
				ListMatrix<Vector<int> > exponents(0,n);
				poly p = singIdeal->m[j];
				std::vector<Rational> coefficients;
				while(p != NULL){
					number c = pGetCoeff(p);
					coefficients.push_back(convert_number_to_Rational(c, singRing));
					Vector<int> monomial(n);
					for(int i = 1; i<=n; i++){
						monomial[i-1] = pGetExp(p, i);
					}
					exponents /= monomial;
					pIter(p);
				}
				polys.push_back(Polynomial<>(exponents, coefficients, r));
            cout << "converted: " << p_String(singIdeal->m[j],singRing,singRing)<<endl;
			}
      }
      return Array<Polynomial<> >(polys);
   }

};

SingularIdeal_wrap* SingularIdeal_wrap::create(const Array<Polynomial<> > gens) 
{
   return new SingularIdeal_impl(gens);
}


UserFunction4perl("# @category Other"
                  "# @param String path Path to the singular directory",
                  &init_singular, "init_singular($)");

} }


