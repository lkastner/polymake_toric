#include "polymake/tvarieties/algebra.h"

#include <libsingular.h>


namespace polymake { namespace tvarieties {

int singular_initialized = 0;

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
   
   std::string p = path+"/lib/libsingular.so";
   char* cpath = omStrDup(p.c_str());
   siInit(cpath);
   WerrorS_callback = &singular_error_handler;
   
   cout << "init_singular done" << endl;
   singular_initialized = 1;
}

Rational convert_number_to_Rational(number* x, ring* ring)
{
   Rational r((nlGetNumerator(*x,*ring))->z,(nlGetDenom(*x,*ring))->z);
   return r;
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

class SingularWrapper_impl : public SingularWrapper {
private:
   ring singRing;
   ideal singIdeal;
   const Ideal* polymakeIdeal; 

	// Initialize a ring for computations in Singular
   void create_singRing() 
   {
      const Ring<>& basering = polymakeIdeal->get_ring();
      int nvars = basering.n_vars();
      if(nvars == 0) 
         throw std::runtime_error("Given ring is not a polynomial ring.");
      char **n=(char**)omalloc(nvars*sizeof(char*));
      for(int i=0; i<nvars; i++)
      {
         n[i] = omStrDup(basering.names()[i].c_str());
      }
      singRing = rDefault(0,nvars,n);
   }

	// Send Polymake ideal to Singular
   void create_singIdeal() 
   {
      int npoly = polymakeIdeal->size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      if(singRing == NULL)
         create_singRing();

      rChangeCurrRing(singRing);

      singIdeal = idInit(npoly,1); // Richtig?
      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(*polymakeIdeal); !mypoly.at_end(); ++mypoly, ++j) {
         poly p = p_ISet(0,singRing);
         
         for(Entire<Polynomial<>::term_hash>::const_iterator term = entire(mypoly->get_terms()); !term.at_end(); ++term)
         {
            poly monomial = p_Init(singRing); // Geht das noch?
            p_SetCoeff(monomial,convert_Rational_to_number(term->second),singRing); // Geht das SetCoeff so?
            
            for(int k = 0; k<term->first.dim(); k++)
            {
               p_SetExp(monomial,k+1,term->first[k]); // Hier war der Ring drinne, muss er wieder rein?
            }
            p_Setm(monomial,singRing); // Ring noetig?
            p = p_Add_q(p,monomial,singRing);
         }
         cout << "poly: " << p_String(p,singRing,singRing) << endl;
         singIdeal->m[j]=p_Copy(p,singRing);
      }
   }
public:
   SingularWrapper_impl() 
   {
      if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating empty SingularWrapper_impl" << endl;
      singRing=NULL;
      singIdeal=NULL;
   }
   
   SingularWrapper_impl(const Ideal* J) 
   {
      if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating SingularWrapper_impl from Ideal" << endl;
      singRing=NULL;
      singIdeal=NULL;
      polymakeIdeal = J;
      create_singRing();
      create_singIdeal();
      cout << "DONE CREATING singular object" << endl;
   }

   SingularWrapper_impl(ring r, ideal i)
   {
      if (!singular_initialized)
         throw std::runtime_error("singular not yet initialized, call init_singular(Path)");
      cout << "creating SingularWrapper_impl from singular stuff" << endl;
      singRing=r;
      singIdeal=i;
   }

	~SingularWrapper_impl() 
   {
      cout << "SingularWrapper_impl cleaning up" <<endl;
      /*if(singRing!=NULL) {
         if(singIdeal!=NULL)
            id_Delete(&singIdeal,singRing);
         //rKill(singRing);
      }*/
      cout << "SingularWrapper_impl destroyed" << endl;
   }

	// Compute a groebner basis of a Polymake ideal using Singular
   SingularWrapper* groebner() 
   {
      if(singIdeal==NULL) {
         create_singIdeal();
      }
      
      rChangeCurrRing(singRing);

      ideal res;
      res = kStd(singIdeal,NULL,testHomog,NULL);
      cout << "DONE COMPUTING std basis" << endl;

      return new SingularWrapper_impl(singRing,res);
//      throw std::runtime_error("created singIdeal");
      // check if singIdeal exists
      // set singulardefaultring
      // call groebner
      // create polymake ideal maybe with singRing and singIdeal
   }

   Array<Polynomial<> > polynomials(const Ring<>& ring)
   {
      rChangeCurrRing(singRing);

      int numgen = IDELEMS(singIdeal);
      Array<Polynomial<> > polys = Array<Polynomial<> >(numgen);

      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(polys); !mypoly.at_end(); ++mypoly, ++j) {
         if(singIdeal->m[j] != NULL)
            cout << p_String(singIdeal->m[j],singRing,singRing)<<endl;
      }
      return polys;
   }

};

SingularWrapper* SingularWrapper::create(const Ideal* J) 
{
   return new SingularWrapper_impl(J);
}

UserFunction4perl("# @category Other"
                  "# @param String path Path to the singular directory",
                  &init_singular, "init_singular($)");
} }

