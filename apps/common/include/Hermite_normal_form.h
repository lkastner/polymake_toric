/* Copyright (c) 1997-2012
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
--------------------------------------------------------------------------------
   $Project: polymake $$Id: Hermite_normal_form.h 10664 2012-03-20 23:14:04Z gawrilow $
*/

#ifndef POLYMAKE_HERMITE_NORMAL_FORM_H
#define POLYMAKE_HERMITE_NORMAL_FORM_H

#include "polymake/client.h"
#include "polymake/SparseMatrix.h"
#include "polymake/Bitset.h"
#include "polymake/Array.h"
#include "polymake/linalg.h"
#include "polymake/numerical_functions.h"
#include "polymake/list"
#include "polymake/GenericStruct.h"

namespace polymake { namespace common {

template <typename Matrix>
perl::ListReturn hermite_normal_form(const Matrix& M){
   typedef typename Matrix::element_type E;
   SparseMatrix2x2<E> U;
   SparseMatrix<E> R, S;
   pm::Matrix<E> N(M);
   
   const int rows = M.rows();
   const int cols = M.cols();
   
   R = unit_matrix<E>(cols);

   int current_row = 0, current_col = 0;

   for(int i = 0; i<rows; i++){
      bool nonzero = true;
      // cout << N(i,current_col) << endl;
      if(N(i,current_col) == 0){
         nonzero = false;
         for(int j = current_col; j<cols; j++){
            if(N(i,j) != 0){
               nonzero = true;
               U.i = current_col;
               U.j = j;
               U.a_ii = 0;
               U.a_ij = 1;
               U.a_ji = 1;
               U.a_jj = 0;
               R.multiply_from_right(U);
               N.multiply_from_right(U);
            }
         }
      }
      if(!nonzero){
         // cout << "Continueing" << endl;
         current_row++;
         continue;
      }
      for(int j = current_col+1; j<cols; j++){
         if(N(i,j) != 0){
            U.i = i;
            U.j = j;
            ExtGCD<E> egcd = ext_gcd(N(i,current_col), N(i,j));
            U.a_ii = egcd.p;
            U.a_ji = egcd.q;
            U.a_ij = egcd.k2;
            U.a_jj = -egcd.k1;
            R.multiply_from_right(U);
            N.multiply_from_right(U);
            // cout << pm::Matrix<E>(N) << endl;
            // cout << U.i<<": "<<U.a_ii <<" " << U.a_ij<<endl<<U.j <<": " <<U.a_ji<<" " << U.a_jj << endl;
         }
      }
      if(N(i,current_col)<0){
         S = unit_matrix<E>(cols);
         S(current_col,current_col) = -1;
         R = R*S;
         N = N*S;
      }
      current_col++;
   }

   

   perl::ListReturn result;
   result << N << R;
   return result;

}

}
}
#endif
