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
#include "polymake/Vector.h"
#include "polymake/client.h"

namespace polymake { namespace common { namespace {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0>
   FunctionInterface4perl( dim_f1, T0 ) {
      perl::Value arg0(stack[0]);
      WrapperReturn( arg0.get<T0>().dim() );
   };

   FunctionInstance4perl(dim_f1, perl::Canned< const pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::IndexedSlice<pm::IndexedSlice<pm::Vector<pm::Integer>&, pm::Series<int, true>, void>&, pm::Series<int, true>, void> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
   FunctionInstance4perl(dim_f1, perl::Canned< const pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::VectorChain<pm::Vector<pm::Rational> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> const&, pm::Vector<pm::Rational> const&> >);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} } }
