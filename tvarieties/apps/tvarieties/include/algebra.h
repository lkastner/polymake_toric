#include "libsingular.h"
#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace polymake { namespace tvarieties {

class Ideal : public Array<Polynomial<> > {
   Ring<> basering;
public:
	Ideal()  {}

	~Ideal() {}

   void set(int i, const Polynomial<> & p) {
      Array<Polynomial<> >::operator[](i)=p;
   }

   const Ring<> & get_ring(){
      return basering;
   }

   void operator+=(const Ideal I) {
      if(basering != get_ring(I)) throw std::runtime_error("Ideals of different rings.");
      append(I.size(),I.begin());
   }

   friend Ideal operator+(const Ideal i1, const Ideal i2) {
      if(get_ring(i1) != get_ring(i2)) throw std::runtime_error("Ideals of different rings.");
      Ideal result(i1);
      result+=i2;
      return result;
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


