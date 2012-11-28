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
#include "polymake/Polynomial.h"
#include "polymake/Rational.h"
#include "polymake/Ring.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   FunctionInstance4perl(new_X, Polynomial< Rational, int >, perl::Canned< const Monomial< Rational, int > >);
   OperatorInstance4perl(BinaryAssign_mul, perl::Canned< Polynomial< Rational, int > >, perl::Canned< const Polynomial< Rational, int > >);
   FunctionInstance4perl(new_X, Polynomial< Rational, int >, perl::Canned< const Polynomial< Rational, int > >);
   OperatorInstance4perl(BinaryAssign_add, perl::Canned< Polynomial< Rational, int > >, perl::Canned< const Monomial< Rational, int > >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Polynomial< Rational, int > >, int);
   FunctionInstance4perl(new_X, Polynomial< Rational, int >, perl::Canned< const Ring< Rational, int > >);
   OperatorInstance4perl(BinaryAssign_add, perl::Canned< Polynomial< Rational, int > >, int);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Polynomial< Rational, int > >, perl::Canned< const Polynomial< Rational, int > >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
