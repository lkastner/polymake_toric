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
#include "polymake/Matrix.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Integer.h"
#include "polymake/SparseMatrix.h"
#include "polymake/Set.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   OperatorInstance4perl(Binary__or, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, false>, void> > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer>&>, pm::Series<int, true>, void> > >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< Vector< Integer > > >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer>&>, pm::Series<int, true>, void> >, perl::Canned< const Matrix< Integer > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary__or, perl::Canned< const Vector< Rational > >, perl::Canned< const pm::MatrixMinor<pm::SparseMatrix<pm::Rational, pm::NonSymmetric> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> >);
   OperatorInstance4perl(Binary__or, perl::Canned< const Vector< Rational > >, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Rational> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_mul, int, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void> > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< Vector< Rational > > >, perl::Canned< const Vector< Integer > >);
   OperatorInstance4perl(Binary__ne, perl::Canned< const Wary< pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_sub, perl::Canned< const Wary< pm::IndexedSlice<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void>, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&, void> > >, perl::Canned< const Vector< Rational > >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> > >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Wary< pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Integer> const&>, pm::Series<int, true>, void> > >, perl::Canned< const Vector< Rational > >);
   FunctionInstance4perl(new_X, Vector< Rational >, perl::Canned< const pm::sparse_matrix_line<pm::AVL::tree<pm::sparse2d::traits<pm::sparse2d::traits_base<pm::Integer, false, false, (pm::sparse2d::restriction_kind)0>, false, (pm::sparse2d::restriction_kind)0> >&, pm::NonSymmetric> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
