#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace polymake { namespace tvarieties {

class Ideal : Array<Polynomial<> > {
public:
	Ideal() {}

	~Ideal() {}
};

// possibly do the following here:

class PrimeDivisor{};
class Divisor{};


} }

