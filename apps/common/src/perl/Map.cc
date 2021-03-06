/* Copyright (c) 1997-2010
   Ewgenij Gawrilow, Michael Joswig (Technische Universitaet Darmstadt, Germany)
   http://www.polymake.org

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

#include "polymake/IncidenceMatrix.h"
#include "polymake/Integer.h"
#include "polymake/Map.h"
#include "polymake/Matrix.h"
#include "polymake/Polynomial.h"
#include "polymake/Rational.h"
#include "polymake/Set.h"
#include "polymake/Vector.h"
#include "polymake/client.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   template <typename T0>
   FunctionInterface4perl( new, T0 ) {
      WrapperReturnNew(T0, () );
   };

   Class4perl("Polymake::common::Map_A_Vector__Int_I_Int_Z", Map< Vector< int >, int >);
   FunctionInstance4perl(new, Map< Vector< int >, int >);
   Class4perl("Polymake::common::Map_A_Set__Int_I_Vector__Integer_Z", Map< Set< int >, Vector< Integer > >);
   FunctionInstance4perl(new, Map< Vector< Integer >, Vector< Integer > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Vector< Integer >, Vector< Integer > > >, perl::Canned< const Vector< Integer > >);
   FunctionInstance4perl(new_X, Map< Vector< Integer >, Vector< Integer > >, perl::Canned< const Map< Vector< Integer >, Vector< Integer > > >);
   Class4perl("Polymake::common::Map_A_Integer_I_Monomial_A_Rational_I_Int_Z_Z", Map< Integer, Monomial< Rational, int > >);
   FunctionInstance4perl(new, Map< Integer, Monomial< Rational, int > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Integer, Monomial< Rational, int > > >, int);
   Class4perl("Polymake::common::Map_A_Vector__Integer_I_Monomial_A_Rational_I_Int_Z_Z", Map< Vector< Integer >, Monomial< Rational, int > >);
   FunctionInstance4perl(new, Map< Vector< Integer >, Monomial< Rational, int > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Vector< Integer >, Monomial< Rational, int > > >, perl::Canned< const Vector< Integer > >);
   Class4perl("Polymake::common::Map_A_Integer_I_Polynomial_A_Rational_I_Int_Z_Z", Map< Integer, Polynomial< Rational, int > >);
   FunctionInstance4perl(new, Map< Integer, Polynomial< Rational, int > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Integer, Polynomial< Rational, int > > >, int);
   Class4perl("Polymake::common::Map_A_Vector__Integer_I_Polynomial_A_Rational_I_Int_Z_Z", Map< Vector< Integer >, Polynomial< Rational, int > >);
   FunctionInstance4perl(new, Map< Vector< Integer >, Polynomial< Rational, int > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Vector< Integer >, Polynomial< Rational, int > > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary_brk, perl::Canned< const Map< Vector< Integer >, Vector< Integer > > >, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_brk, perl::Canned< Map< Integer, Monomial< Rational, int > > >, perl::Canned< const Integer >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
