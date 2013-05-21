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

#include "polymake/client.h"
#include "polymake/perl/assoc.h"
#include "polymake/Map.h"
#include "polymake/Vector.h"
#include "polymake/Rational.h"
#include "polymake/Matrix.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Integer.h"
#include "polymake/Polynomial.h"
#include "polymake/Set.h"
namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( assoc_find_X_X, T0,T1 ) {
      perl::Value arg0(stack[0]), arg1(stack[1]);
      WrapperReturn( pm::perl::find_element(arg0.get<T0>(), arg1.get<T1>()) );
   };

   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Vector< Rational >, int > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Integer, Monomial< Rational, int > > >, int);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Vector< Integer >, Polynomial< Rational, int > > >, perl::Canned< const Vector< Integer > >);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Vector< Integer >, Monomial< Rational, int > > >, perl::Canned< const Vector< Integer > >);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Vector< Integer >, Vector< Integer > > >, perl::Canned< const Vector< Integer > >);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Vector< Integer >, Vector< Integer > > >, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(assoc_find_X_X, perl::Canned< const Map< Set< int >, Vector< Rational > > >, perl::Canned< const pm::incidence_line<pm::AVL::tree<pm::sparse2d::traits<pm::sparse2d::traits_base<pm::nothing, true, false, (pm::sparse2d::restriction_kind)0>, false, (pm::sparse2d::restriction_kind)0> > const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
