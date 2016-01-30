/*
  Copyright (c) 2011-12 Andreas Paffenholz
 
  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version: http://www.gnu.org/licenses/gpl.txt.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
-------------------------------------------------------------------------------
  $Project: toric_varieties $$Id: cones.cc 202 2012-03-11 16:48:31Z paffenholz $
*/

#include "polymake/client.h"
#include "polymake/Matrix.h"
#include "polymake/Array.h"
#include "polymake/SparseMatrix.h"
#include "polymake/Integer.h"
#include "polymake/Rational.h"
#include "polymake/common/lattice_tools.h"

namespace polymake { namespace fulton {

    // Computes the nef cone of the toric variety corresponding to the fan ''F'' given in the input
    // also known as the (closure of the) Kaehler cone
    // dual to the Mori cone in the space of the rational divisor class group
    //
    // algorithm: 
    // compute a basis ''ker'' of all integral dependencies of the rays 
    // columns of ''ker'' are the Gale dual of the rays
    // for each maximal cone ''s_i'' in the fan ''F'': 
    // let C be the cone spanned by the columns of ''ker'' with index not in the cone
    // a divisor is nef if it lies in all cones C_i
    //
    // probably not the most efficient algorithm: involves several ch computations
    // maybe better approach: 
    // use that a divisor ''D'' is nef if and only if its intersection with all T-invariant curves is non-negative
    // i.e. in the polytope ''P_D'' all edge lengths of edges defined by codim(1)-faces of ''F''
    // must be non-negative
    perl::Object nef_cone( perl::Object fan ) {

      Matrix<Rational> rays = fan.give("RAYS");
      Array<Set<int> > max_cones = fan.give("MAXIMAL_CONES");
      Matrix<Integer> ker;
      Matrix<Integer> t_int_rays=T(common::primitive(rays));

      // here we call the perl function "integer_kernel" defined in the 
      // lll-extension (http://polymake.org/polytopes/paffenholz/data/polymake/extensions/lll). 
      // this should be replaced by a c++-call 
      // once we can detec the ntl extension (see ticket #504), or ntl is a core extension
      CallPolymakeFunction("integer_kernel",t_int_rays,false) >> ker;

      perl::Object nef_t1("Cone<Rational>");      
      nef_t1.take("INPUT_RAYS") << T(ker.minor(All,~max_cones[0]));

      for ( int i = 1; i < max_cones.size(); ++i ) {	
	perl::Object nef_t2("Cone<Rational>");
	nef_t2.take("INPUT_RAYS") << T(ker.minor(All,~max_cones[i]));
	nef_t1 = CallPolymakeFunction("polytope::intersection", nef_t1, nef_t2);
      }

      // the rule creating the nef cone wants to know the exact set of properties created. 
      // So we create a new cone and copy FACETS and LINEAR_SPAN
      // (this involves a ch reduction, nef_t1 ony contains INEQUALITIES and EQUATIONS)
      perl::Object nef("Cone<Rational>");      
      Matrix<Rational> facets = nef_t1.give("FACETS");
      Matrix<Rational> affine_hull = nef_t1.give("LINEAR_SPAN");
      nef.take("FACETS") << facets;
      nef.take("LINEAR_SPAN") << affine_hull;
            
      return nef;
    }

    // Computes the cone of effective divisors
    // defined in the space of the rational divisor clas group
    // a divisor is effective if all coeffs are non-negative up to numerical equivalence
    // 
    // algorithm: 
    // a class of divisors ''D'' contains an effective divisor if and only if the 
    // polytope ''P_D'' defined by the divisor is non-empty
    perl::Object effective_cone( perl::Object fan ) {

      Matrix<Rational> tmp = fan.give("RAYS");
      Matrix<Integer> class_group_lifting = fan.give("RATIONAL_DIVISOR_CLASS_GROUP.LIFTING");

      Matrix<Integer> rays = common::primitive(tmp);

      perl::Object pc("PointConfiguration<Rational>");
      pc.take("POINTS") << (ones_vector<Integer>(rays.rows())|rays)/(unit_vector<Integer>(rays.cols()+1,0));

      Array<Set<int> > positive_circuits = CallPolymakeFunction("positive_circuits", pc, rays.rows() );
      
      Matrix<Integer> I(0,rays.rows());
      for ( Entire<Array<Set<int> > >::const_iterator pcIt = entire ( positive_circuits ); !pcIt.at_end(); ++pcIt ) {

	Matrix<Integer> NS = null_space(T(rays.minor(*pcIt,All)));
	if ( NS.rows() != 1 )     
	  throw std::runtime_error("effective_cone: computation of positive circuits failed");
	
	Vector<Integer> comb = common::primitive(NS.row(0));
	if ( comb[0] < 0 ) comb *= -1;

	Vector<Integer> ineq(rays.rows());
	int i = 0;
	for ( Entire<Set<int> >::const_iterator sIt = entire(*pcIt); !sIt.at_end(); ++sIt, ++i )
	  ineq[*sIt] = comb[i];

	I /= class_group_lifting*ineq;

      }

      perl::Object eff("Cone<Rational>");      
      eff.take("INEQUALITIES") << I;
      return eff;
    }



    Function4perl(&effective_cone, "effective_cone($)");

    Function4perl(&nef_cone, "nef_cone($)");

  }}
