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
#include "polymake/Integer.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Set.h"
#include "polymake/Rational.h"
#include "polymake/linalg.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0>
   FunctionInterface4perl( transpose_X, T0 ) {
      perl::Value arg0(stack[0]);
      WrapperReturn( T(arg0.get<T0>()) );
   };

   FunctionInstance4perl(transpose_X, perl::Canned< const pm::MatrixMinor<pm::Matrix<pm::Integer> const&, pm::all_selector const&, pm::Complement<pm::SingleElementSet<int const&>, int, pm::operations::cmp> const&> >);
   FunctionInstance4perl(transpose_X, perl::Canned< const pm::ColChain<pm::ColChain<pm::Matrix<pm::Rational> const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > const&, pm::SingleCol<pm::SameElementVector<pm::Rational const&> const&> > >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
