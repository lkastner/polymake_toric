#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"
#include "polymake/tvarieties/algebra.h"

#include <libsingular.h>


namespace polymake { namespace tvarieties {

int singular_initialized = 0;

void init_singular() {
   if(singular_initialized)
      return;

   siInit("/home/forti/polymake/install/singular/lib/libsingular.so");

   //throw std::runtime_error("Could not initialize singular");
}

Rational& convert_number_to_Rational(number* x, ring* ring)
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

   void create_singRing() 
   {
      const Ring<>& basering = polymakeIdeal->get_ring();
      int nvars = basering.n_vars();
      if(nvars == 0) throw std::runtime_error("Given ring is not a polynomial ring.");
      char **n=(char**)omalloc(nvars*sizeof(char*));
      for(int i=0; i<nvars; i++)
      {
         n[i] = omStrDup(basering.names()[i].c_str());
      }
      singRing = rDefault(0,nvars,n);
   }

   void create_singIdeal() 
   {
      int npoly = polymakeIdeal->size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      if(singRing == NULL)
         create_singRing();

      rChangeCurrRing(singRing);

      singIdeal = idInit(npoly,1);
      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(*polymakeIdeal); !mypoly.at_end(); ++mypoly, ++j) {
         poly p = p_ISet(0,singRing);
         
         for(Entire<Polynomial<>::term_hash>::const_iterator term = entire(mypoly->get_terms()); !term.at_end(); ++term)
         {
            poly monomial = p_Init(singRing);
            p_SetCoeff(monomial,convert_Rational_to_number(term->second),singRing);
            
            for(int k = 0; k<term->first.dim(); k++)
            {
               p_SetExp(monomial,k+1,term->first[k],singRing);
            }
            p_Setm(monomial,singRing);
            p = p_Add_q(p,monomial,singRing);
         }
         singIdeal->m[j]=p;
      }
   }
public:
   SingularWrapper_impl() 
   {
      init_singular();

      singRing=NULL;
      singIdeal=NULL;
   }
   
   SingularWrapper_impl(const Ideal* J) 
   {
      init_singular();

      singRing=NULL;
      singIdeal=NULL;
      polymakeIdeal = J;
      create_singRing();
      create_singIdeal();
      cout << "DONE CREATING singular object" << endl;
   }

//	~SingularWrapper_impl() {}

   void groebner() 
   {
      if(singIdeal==NULL) {
         create_singIdeal();
      }
      ideal res;
      res = kStd(singIdeal,NULL,testHomog,NULL);
      cout << "DONE COMPUTING std basis" << endl;
//      throw std::runtime_error("created singIdeal");
      // check if singIdeal exists
      // set singulardefaultring
      // call groebner
      // create polymake ideal maybe with singRing and singIdeal
   }

};

SingularWrapper* SingularWrapper::create(const Ideal* J) 
{
   return new SingularWrapper_impl(J);
}

} }


