#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"

namespace polymake { namespace tvarieties {

class Ideal {
	Array<Polynomial<> > gens;
public:
   Ideal() {}

   ~Ideal() {}

Ideal(const Array<Polynomial<> >& g)
{
gens = g;
}

template <typename Output> friend
Output& operator<< (GenericOutput<Output>& out, const Ideal& me)
   {
      out.top() << "bla\n";
      return out.top();
   }

};

// possibly do the following here:

class PrimeDivisor{};
class Divisor{};


} }

