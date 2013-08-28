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
#include "polymake/Vector.h"
#include "polymake/Integer.h"
#include "polymake/Rational.h"
#include "polymake/IncidenceMatrix.h"
namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( slice_X_f5, T0,T1 ) {
      perl::Value arg0(stack[0]), arg1(stack[1]);
      WrapperReturnLvalue( T0, arg0.get<T0>().slice(arg1.get<T1>()) );
   };

   template <typename T0>
   FunctionInterface4perl( slice_x_x_f5, T0 ) {
      perl::Value arg0(stack[0]), arg1(stack[1]), arg2(stack[2]);
      WrapperReturnLvalue( T0, arg0.get<T0>().slice(arg1, arg2) );
   };

   FunctionInstance4perl(slice_x_x_f5, perl::Canned< Wary< Vector< Integer > > >);
   FunctionInstance4perl(slice_x_x_f5, perl::Canned< Wary< pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> > >);
   FunctionInstance4perl(slice_x_x_f5, perl::Canned< Wary< pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> > >);
   FunctionInstance4perl(slice_x_x_f5, perl::Canned< Wary< pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> > >);
   FunctionInstance4perl(slice_X_f5, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::incidence_line<pm::AVL::tree<pm::sparse2d::traits<pm::sparse2d::traits_base<pm::nothing, true, false, (pm::sparse2d::restriction_kind)0>, false, (pm::sparse2d::restriction_kind)0> > const&> >);
   FunctionInstance4perl(slice_X_f5, perl::Canned< Wary< Vector< Rational > > >, int);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
