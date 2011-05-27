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
#include "polymake/tvarieties/algebra.h"
#include "polymake/Polynomial.h"
#include "polymake/Rational.h"
namespace polymake { namespace tvarieties {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( set_int_X_f17, T0,T1 ) {
      perl::Value arg0(stack[0]), arg1(stack[1]), arg2(stack[2]);
      WrapperReturnVoid( arg0.get<T0>().set(arg1.get<int>(), arg2.get<T1>()) );
   };

   FunctionInstance4perl(set_int_X_f17, perl::Canned< Ideal >, perl::Canned< const Polynomial< Rational, int > >);
   FunctionInstance4perl(set_int_X_f17, perl::Canned< Ideal >, perl::Canned< const Monomial< Rational, int > >);

///==== Automatically generated contents end here.  Please do not delete this line. ====

} }