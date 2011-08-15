#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"
#include "polymake/tvarieties/algebra.h"

namespace singular {

#include <libsingular.h>

}

namespace polymake { namespace tvarieties {

static Rational& convert_number_to_Rational(singular::number* x, singular::ring* ring)
{
   Rational r((singular::nlGetNumerator(*x,*ring))->z,(singular::nlGetDenom(*x,*ring))->z);
   return r;
}

static singular::number convert_Rational_to_number(const Rational& r)
{
   mpz_t num, denom;
   mpz_init(num);
   mpz_set(num,numerator(r).get_rep());
   mpz_init(denom);
   mpz_set(denom,denominator(r).get_rep());

   return singular::nlInit2gmp(num,denom);
}

class SingularWrapper_impl : public SingularWrapper {
private:
   singular::ring singRing;
   singular::ideal singIdeal;
   const Ideal* polymakeIdeal; 

   void create_singRing() 
   {
      const Ring<>& basering = polymakeIdeal->get_ring();
      int nvars = basering.n_vars();
      if(nvars == 0) throw std::runtime_error("Given ring is not a polynomial ring.");
      char **n=(char**)singular::omalloc(nvars*sizeof(char*));
      for(int i=0; i<nvars; i++)
      {
         n[i] = singular::omStrDup(basering.names()[i].c_str());
      }
      singRing = singular::rDefault(0,nvars,n);
   }

   void create_singIdeal() 
   {
      int npoly = polymakeIdeal->size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      if(singRing == NULL)
         create_singRing();

      singular::rChangeCurrRing(singRing);

      singIdeal = singular::idInit(npoly,1);
      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(*polymakeIdeal); !mypoly.at_end(); ++mypoly, ++j) {
         singular::poly p = singular::p_ISet(0,singRing);
         
         for(Entire<Polynomial<>::term_hash>::const_iterator term = entire(mypoly->get_terms()); !term.at_end(); ++term)
         {
            singular::poly monomial = singular::p_Init(singRing);
            singular::p_SetCoeff(monomial,convert_Rational_to_number(term->second),singRing);
            
            for(int k = 0; k<term->first.dim(); k++)
            {
               singular::p_SetExp(monomial,k+1,term->first[k],singRing);
            }
            singular::p_Setm(monomial,singRing);
            p = singular::p_Add_q(p,monomial,singRing);
         }
         singIdeal->m[j]=p;
      }
   }
public:
   SingularWrapper_impl() 
   {
      singRing=NULL;
      singIdeal=NULL;
   }
   
   SingularWrapper_impl(const Ideal* J) 
   {
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
      throw std::runtime_error("created singIdeal");
      // check if singIdeal exists
      // set singulardefaultring
      // call groebner
      // create polymake ideal maybe with singRing and singIdeal
   }

};

SingularWrapper* SingularWrapper::create(const Ideal* J) 
{
   return static_cast<SingularWrapper*>(new SingularWrapper_impl(J));
}

} }


