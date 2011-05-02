#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

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

	operator() (int i) 
	{
		return gens[i];
	}
	operator() (int i) const
	{
		return gens[i];
	}

template <typename Output> friend
Output& operator<< (GenericOutput<Output>& out, const Ideal& me)
	{
		for(Array<Polynomial<> >::const_iterator it = me.gens.begin(); it != me.gens.end(); ++it) {
			out.top() << *it << "\n";
		}
		out.top() << "number of gens: ";
		out.top() << me.gens.size();
		return out.top();
	}

};

// possibly do the following here:

class PrimeDivisor{};
class Divisor{};


} }

