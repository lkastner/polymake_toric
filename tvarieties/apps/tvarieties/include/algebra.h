#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace singular {

#include <libsingular.h>

}

namespace polymake { namespace tvarieties {

class Ideal : public Array<Polynomial<> > {
   singular::ring singRing;

   void create_singRing() 
   {
      
   }

   void create_singIdeal() 
   {
      int npoly = this->size();
      if(!npoly)
         throw std::runtime_error("Ideal has no generators.");
      if(singRing == NULL)
         create_singRing();

      singular::rChangeCurrRing(singRing);

      Array<singular::poly> polynomials(npoly);

      Entire<Array<Polynomial<> > >::const_iterator mypoly = entire(*this);
      for(Entire<Array<singular::poly> >::iterator poly=entire(polynomials); !poly.at_end(); ++mypoly, ++poly) {
         

      }
public:
	Ideal()  {}

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


