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
#include "polymake/tvarieties/algebra.h"
namespace polymake { namespace tvarieties {
///==== Automatically generated contents follow.    Please do not delete this line. ====
   template <typename T0>
   FunctionInterface4perl( new, T0 ) {
      WrapperReturnNew(T0, () );
   };

   FunctionInstance4perl(new, Ideal);
   OperatorInstance4perl(BinaryAssign_add, perl::Canned< Ideal >, perl::Canned< const Ideal >);
   OperatorInstance4perl(Binary_add, perl::Canned< const Ideal >, perl::Canned< const Ideal >);
   Class4perl("Polymake::tvarieties::Ideal", Ideal);
///==== Automatically generated contents end here.  Please do not delete this line. ====
} }
