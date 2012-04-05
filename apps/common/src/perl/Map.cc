/* Copyright (c) 1997-2010
   Ewgenij Gawrilow, Michael Joswig (Technische Universitaet Darmstadt, Germany)
   http://www.polymake.de

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version: http://www.gnu.org/licenses/gpl.txt.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
*/

///==== this line controls the automatic file splitting: max.instances=40

#include "polymake/client.h"
#include "polymake/Map.h"
#include "polymake/Set.h"
#include "polymake/Vector.h"
#include "polymake/Rational.h"
#include "polymake/Polynomial.h"
#include "polymake/Matrix.h"
#include "polymake/IncidenceMatrix.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0>
   FunctionInterface4perl( new, T0 ) {
      WrapperReturnNew(T0, () );
   };

   Class4perl("Polymake::common::Map_A_Set__Int_I_Vector__Rational_Z", Map< Set< int >, Vector< Rational > >);
   Class4perl("Polymake::common::Map_A_Set__Int_I_Polynomial_A_Rational_I_Int_Z_Z", Map< Set< int >, Polynomial< Rational, int > >);
   Class4perl("Polymake::common::Map_A_Vector__Int_I_Int_Z", Map< Vector< int >, int >);
   FunctionInstance4perl(new, Map< Vector< int >, int >);
   Class4perl("Polymake::common::Map_A_Vector__Rational_I_Int_Z", Map< Vector< Rational >, int >);
   FunctionInstance4perl(new, Map< Vector< Rational >, int >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Vector< Rational >, int > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
