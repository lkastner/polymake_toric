#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace polymake { namespace tvarieties {

class Ideal : public Array<Polynomial<> > {
public:
	Ideal()  {}

	~Ideal() {}

   void set(int i, const Polynomial<> & p) {
      Array<Polynomial<> >::operator[](i)=p;
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


