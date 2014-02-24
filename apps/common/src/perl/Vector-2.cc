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
#include "polymake/SparseMatrix.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/linalg.h"
#include "polymake/Matrix.h"
#include "polymake/Set.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(assign, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, Vector< Integer >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, false>, void> > >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(assign, pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, perl::Canned< const Integer >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::ContainerUnion<pm::cons<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void>, pm::Vector<pm::Rational> const&>, void> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::incidence_line<pm::AVL::tree<pm::sparse2d::traits<pm::sparse2d::traits_base<pm::nothing, true, false, (pm::sparse2d::restriction_kind)0>, false, (pm::sparse2d::restriction_kind)0> > const&> const&, pm::all_selector const&> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Integer > > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const Vector< Rational > >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::VectorChain<pm::SameElementVector<pm::Rational const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::VectorChain<pm::Vector<pm::Rational> const&, pm::SameElementVector<pm::Rational const&> const&> >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::IndexedSlice<pm::Vector<pm::Rational>&, pm::Series<int, true>, void> const&, pm::SameElementVector<pm::Rational const&> const&> const&, pm::IndexedSlice<pm::Vector<pm::Rational>&, pm::Series<int, true>, void> const&> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::VectorChain<pm::SameElementVector<pm::Integer const&> const&, pm::Vector<pm::Integer> const&> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> const&, pm::SameElementVector<pm::Integer const&> const&> const&, pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> const&> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, perl::Canned< const pm::SameElementVector<pm::Rational const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
