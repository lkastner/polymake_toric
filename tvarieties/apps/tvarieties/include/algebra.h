#include "polymake/client.h"
#include "polymake/Array.h"
#include "polymake/Ring.h"
#include "polymake/Polynomial.h"
#include "polymake/internal/shared_object.h"

namespace polymake { namespace tvarieties {

class Ideal;

void init_singular(const std::string& path);

class SingularWrapper {
public:

   virtual SingularWrapper* groebner() = 0;

   virtual Array<Polynomial<> > polynomials() = 0;
   

   static SingularWrapper* create(const Ideal* J);

};

class Ideal : public Array<Polynomial<> > {
private:
   SingularWrapper* singObj;

public:
   Ideal() : Array<Polynomial<> >()  
   {
      singObj=NULL;
   }

   Ideal(Array<Polynomial<> > polys, SingularWrapper* wrap) : 
      Array<Polynomial<> >(polys) 
   {
      singObj=wrap;
   }


 /*  void set(int i, const Polynomial<> & p) {
      Array<Polynomial<> >::operator[](i)=p;
   }
*/
   const Ring<>& get_ring() const {
      if(this->empty()) {
         Ring<> r = Ring<>();
         return r;  
      } else {
         const Polynomial<>& poly = this->front();
         return poly.get_ring();
      }
//      return (this->empty() ? Ring<>() : (*this)[0].get_ring());
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
      if(singObj == NULL) {
         //Ideal* writable = const_cast<Ideal*>(this);
         singObj = SingularWrapper::create(this);
      }
      SingularWrapper* basis = singObj->groebner();
      return Ideal(basis->polynomials(),basis);

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


