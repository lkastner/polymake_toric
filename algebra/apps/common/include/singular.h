#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace polymake { namespace common {

class SingularIdeal_wrap {
public:
   virtual ~SingularIdeal_wrap() {cout << "SingularIdeal destroyed" << endl; }

   virtual void std(const Ring<> r) = 0;

   virtual Array<Polynomial<> > polynomials(const Ring<> r) const = 0;
   
   static SingularIdeal_wrap* create(const Array<Polynomial<> > gens);

};

class SingularIdeal {
private:
   SingularIdeal_wrap* singIdeal;

public:
   SingularIdeal(const Array<Polynomial<> > gens) {
      singIdeal = SingularIdeal_wrap::create(gens);
   }

   void std(const Ring<> r) const  {
      singIdeal->std(r);
   }

   Array<Polynomial<> > polynomials(const Ring<> r) const {
      return singIdeal->polynomials(r);
   }
};



/*
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
      if(singObj == NULL) {
         //Ideal* writable = const_cast<Ideal*>(this);
         singObj = SingularIdeal::create(this);
      }
      SingularIdeal* basis = singObj->groebner();
      return Ideal(basis->polynomials(this->get_ring()),basis);

   }

};
*/


} }


