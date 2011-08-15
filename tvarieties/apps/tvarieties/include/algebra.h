#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

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

class Ideal : public Array<Polynomial<> > {
   singular::ring singRing;
   singular::ideal I;
   
      
   void create_singRing() 
   {
      const Ring<>& basering = get_ring();
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
      int npoly = this->size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      if(singRing == NULL)
         create_singRing();

      singular::rChangeCurrRing(singRing);

      I = singular::idInit(npoly,1);
      int j = 0;
      for(Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(*this); !mypoly.at_end(); ++mypoly, ++j) {
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
         I->m[j]=p;
      }
   }
public:
   Ideal() : Array<Polynomial<> >() 
   {
      singRing=NULL;
      I=NULL;
   }

	~Ideal() {}

   void set(int i, const Polynomial<> & p) {
      Array<Polynomial<> >::operator[](i)=p;
   }

   const Ring<>& get_ring() const {
      return (this->empty() ? Ring<>() : this->front().get_ring());
   }

   Ideal& operator+=(const Ideal& I) {
      if(this->get_ring() != I.get_ring()) throw std::runtime_error("Ideals of different rings.");
      append(I.size(),I.begin());
      return static_cast<Ideal&>(*this);
   }

   friend Ideal operator+(const Ideal& i1, const Ideal& i2) {
      if(i1.get_ring() != i2.get_ring()) throw std::runtime_error("Ideals of different rings.x");
      Ideal result = i1;
      result+=i2;
      return result;
   }

   Ideal groebner() 
   {
      if(I==NULL)
         create_singIdeal();
      // check if singIdeal exists
      // set singulardefaultring
      // call groebner
      // create polymake ideal maybe with singRing and singIdeal
   }
};


// possibly do the following here:

class PrimeDivisor{};
class Divisor{};


} }

namespace pm {

template <>
struct spec_object_traits< polymake::tvarieties::Ideal >
   : spec_object_traits<is_container> {};

} // end namespace pm


