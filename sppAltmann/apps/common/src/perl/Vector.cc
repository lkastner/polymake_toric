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
#include "polymake/Vector.h"
#include "polymake/Rational.h"
#include "polymake/Integer.h"
#include "polymake/linalg.h"
#include "polymake/Matrix.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Array.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(assign, Vector< Rational >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary__eq, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::SameElementVector<pm::Rational const&> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< Vector< Integer > > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const Vector< Integer > >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(Binary__or, int, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::VectorChain<pm::SingleElementVector<int const&>, pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> const&> >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::SameElementVector<pm::Rational const&> >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::SameElementVector<pm::Rational const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::VectorChain<pm::SameElementVector<pm::Rational const&> const&, pm::Vector<pm::Rational> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Transposed<pm::Matrix<pm::Rational> > const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::SameElementVector<pm::Rational const&> > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Transposed<pm::Matrix<pm::Rational> > const&> >);
   OperatorInstance4perl(Binary_mul, int, perl::Canned< const Wary< Vector< Rational > > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, Vector< Rational >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::SameElementVector<pm::Rational const&> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary__eq, perl::Canned< const Wary< pm::SameElementVector<pm::Rational const&> > >, perl::Canned< const pm::SameElementVector<pm::Rational const&> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::IndexedSlice<pm::Vector<pm::Rational> const&, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const Vector< Rational > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::SameElementVector<pm::Rational const&> >, perl::Canned< const pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::SameElementVector<pm::Rational const&> >, perl::Canned< const pm::Transposed<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Array<int, void> const&> > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::SameElementVector<pm::Rational const&> >, perl::Canned< const pm::ColChain<pm::Matrix<pm::Rational> const&, pm::Matrix<pm::Rational> const&> >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Rational> const&, pm::Series<int, true>, void> >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
