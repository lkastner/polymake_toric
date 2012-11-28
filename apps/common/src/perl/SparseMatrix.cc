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
#include "polymake/SparseMatrix.h"
#include "polymake/Rational.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Vector.h"
#include "polymake/linalg.h"
#include "polymake/Matrix.h"
#include "polymake/Set.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0, typename T1>
   FunctionInterface4perl( new_X, T0,T1 ) {
      perl::Value arg0(stack[1]);
      WrapperReturnNew(T0, (arg0.get<T1>()) );
   };

   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> >);
   OperatorInstance4perl(Unary_neg, perl::Canned< const Wary< pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> > >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> >);
   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::RowChain<pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> const&, pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> >);
   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::RowChain<pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> const&, pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> const&> >);
   OperatorInstance4perl(Binary_div, perl::Canned< const Wary< pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> > >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> >);
   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::RowChain<pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::SparseMatrix<pm::Rational, pm::Symmetric> const&> const&, pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::DiagMatrix<pm::SameElementVector<pm::Rational const&>, true> const&> const&> >);
   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::RowChain<pm::SingleRow<pm::SameElementSparseVector<pm::SingleElementSet<int>, pm::Rational> const&>, pm::ColChain<pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&>, pm::Matrix<pm::Rational> const&> const&> >);
   FunctionInstance4perl(new_X, SparseMatrix< Rational, NonSymmetric >, perl::Canned< const pm::ColChain<pm::SingleCol<pm::Vector<pm::Rational> const&>, pm::MatrixMinor<pm::SparseMatrix<pm::Rational, pm::NonSymmetric> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
