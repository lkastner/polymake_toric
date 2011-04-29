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

Ideal(const Polynomial<>& p) : gens()
	{
		gens.resize(1);
		gens[0] = p;
	}

template <typename Output> friend
Output& operator<< (GenericOutput<Output>& out, const Ideal& me)
	{
		out.top() << me.gens[0];
		out.top() << "\nnumber of gens: ";
		out.top() << me.gens.size();
		return out.top();
	}

};

// possibly do the following here:

class PrimeDivisor{};
class Divisor{};


} }

