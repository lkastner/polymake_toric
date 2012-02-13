/* Copyright (c) 1997-2012
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
--------------------------------------------------------------------------------
   $Project: polymake $$Id: lattice_normalization.cc 10542 2012-01-13 00:00:33Z gawrilow $
*/

#include "polymake/client.h"
#include "polymake/Integer.h"
#include "polymake/Rational.h"
#include "polymake/SparseMatrix.h"
#include "polymake/SparseVector.h"
#include "polymake/Matrix.h"
#include "polymake/Vector.h"
#include "polymake/Smith_normal_form.h"
#include "polymake/linalg.h"
#include "polymake/polytope/lattice_tools.h"

namespace polymake { namespace common {
    
    

std::pair<SparseMatrix<Integer>, SparseMatrix<Integer> > smith_normal_form(Matrix<Integer> V)
{
  SparseMatrix<Integer> M(V), L, R;
  std::list< std::pair<Integer,int> > torsion;
  int r = Smith_normal_form(M, torsion, L, R, pm::True());
      
  return std::pair<SparseMatrix<Integer>, SparseMatrix<Integer> >(L, R);
}

UserFunction4perl("# @category Transforming a lattice polyhedron"
                  "# Transform to a full-dimensional polytope while preserving"
                  "# the ambient lattice Z^n"
                  "# @param Polytope p the input polytope,"
                  "# @option Bool store_transform store the reverse transformation as an attachement"
                  "# @return Polytope - the transformed polytope defined by its vertices."
                  "#  Facets are only written if available in //p//.",
                  &smith_normal_form, "smith_normal_form(Matrix<Integer>)");

} }

// Local Variables:
// mode:C++
// c-basic-offset:2
// indent-tabs-mode:nil
// End:
