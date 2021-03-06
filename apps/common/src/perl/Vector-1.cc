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
#include "polymake/Matrix.h"
#include "polymake/Rational.h"
#include "polymake/Set.h"
#include "polymake/SparseMatrix.h"
#include "polymake/Vector.h"
#include "polymake/client.h"
#include "polymake/linalg.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::VectorChain<pm::SameElementVector<pm::Rational const&> const&, pm::Vector<pm::Rational> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Transposed<pm::Matrix<pm::Rational> > const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Transposed<pm::Matrix<pm::Rational> > const&> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::Vector<pm::Rational> const&, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(BinaryAssign_mul, perl::Canned< Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, false>, void> > >, perl::Canned< const Rational >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, false>, void> >);
   OperatorInstance4perl(assign, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const Matrix< Rational > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::VectorChain<pm::SameElementVector<pm::Rational const&> const&, pm::SameElementVector<pm::Rational const&> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Matrix<pm::Rational> const&> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void>, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, void> >);
   OperatorInstance4perl(assign, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Integer >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
