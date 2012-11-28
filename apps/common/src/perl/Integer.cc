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
#include "polymake/Integer.h"
#include "polymake/Matrix.h"
#include "polymake/Rational.h"
#include "polymake/IncidenceMatrix.h"
#include "polymake/Vector.h"
namespace polymake { namespace common {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   OperatorInstance4perl(Binary__le, perl::Canned< const Integer >, perl::Canned< const Integer >);
   OperatorInstance4perl(Binary__le, int, perl::Canned< const Integer >);
   OperatorInstance4perl(Binary__ge, perl::Canned< const Integer >, int);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Integer >, perl::Canned< const pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational>&>, pm::Series<int, true>, void> >);
   OperatorInstance4perl(Binary_mul, perl::Canned< const Integer >, perl::Canned< const pm::ContainerUnion<pm::cons<pm::IndexedSlice<pm::masquerade<pm::ConcatRows, pm::Matrix_base<pm::Rational> const&>, pm::Series<int, true>, void>, pm::Vector<pm::Rational> const&>, void> >);
   OperatorInstance4perl(BinaryAssign_div, perl::Canned< Integer >, long);
   OperatorInstance4perl(Binary__lt, perl::Canned< const Integer >, int);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
