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
#include "polymake/Matrix.h"
#include "polymake/Rational.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Vector.h"
#include "polymake/Set.h"
#include "polymake/Integer.h"
#include "polymake/linalg.h"
#include "polymake/Array.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::RowChain<pm::RowChain<pm::RowChain<pm::RowChain<pm::RowChain<pm::RowChain<pm::RowChain<pm::Matrix<pm::Rational> const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > const&, pm::SingleRow<pm::Vector<pm::Rational> const&> > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::ColChain<pm::ColChain<pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Transposed<pm::Matrix<pm::Rational> >&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, pm::all_selector const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::ColChain<pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Transposed<pm::Matrix<pm::Rational> >&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, pm::all_selector const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Integer > > >, perl::Canned< const pm::DiagMatrix<pm::SameElementVector<pm::Integer const&>, true> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Integer > > >, perl::Canned< const Matrix< Integer > >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer>&>, pm::Series<int, true>, void> const&>, pm::Matrix<pm::Integer> const&> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::Matrix<pm::Rational> const&> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::MatrixMinor<pm::Matrix<pm::Rational> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::Matrix<pm::Integer> > > >, perl::Canned< const Matrix< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::Matrix<pm::Integer> > > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::RowChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> >);
   FunctionInstance4perl(new_X, Matrix< Rational >, perl::Canned< const pm::RowChain<pm::RowChain<pm::Matrix<pm::Rational> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, pm::Array<int, void> const&, void> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
