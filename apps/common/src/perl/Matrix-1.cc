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

///==== this line controls the automatic file splitting: max.instances=20

#include "polymake/client.h"
#include "polymake/Matrix.h"
#include "polymake/Integer.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Rational.h"
#include "polymake/Vector.h"
#include "polymake/linalg.h"
#include "polymake/Array.h"
#include "polymake/Graph.h"
#include "polymake/Set.h"
#include "polymake/SparseMatrix.h"
namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Integer > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<int>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::RowChain<pm::SingleRow<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> const&>, pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Transposed<pm::Matrix<pm::Rational> > const&> const&> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::Matrix<pm::Rational> > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Rational > > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::Array<int, void> const&, pm::all_selector const&> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(assign, pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Array<int, void> const&>, perl::Canned< const Matrix< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Matrix<pm::Rational> const&> > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Matrix< Integer > > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Rational> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > >);
   OperatorInstance4perl(Binary_mul, int, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Matrix<pm::Rational> const&> > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::MatrixMinor<pm::Matrix<pm::Integer> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > > >, perl::Canned< const pm::Transposed<pm::Matrix<pm::Integer> > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::MatrixMinor<pm::Matrix<pm::Integer> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > > >, perl::Canned< const pm::Transposed<pm::MatrixMinor<pm::Matrix<pm::Integer> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::Matrix<pm::Rational> > > >, perl::Canned< const Matrix< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::Transposed<pm::ColChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > > > >, perl::Canned< const Matrix< Rational > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::RowChain<pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&> > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::RowChain<pm::RowChain<pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&> const&, pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&> > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::MatrixMinor<pm::Matrix<pm::Rational>&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::Matrix<pm::Rational> const&, pm::Matrix<pm::Rational> const&> > >, perl::Canned< const pm::ColChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::Matrix<pm::Rational> const&> const&, pm::Matrix<pm::Rational> const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
