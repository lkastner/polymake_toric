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

#include "polymake/SparseMatrix.h"
#include "polymake/Bitset.h"
#include "polymake/Array.h"
#include "polymake/linalg.h"
#include "polymake/numerical_functions.h"
#include "polymake/list"
#include "polymake/GenericStruct.h"

namespace pm { namespace common {

class dummy_companion_logger {
public:
   template <typename E>
   void from_right(const SparseMatrix2x2<E>&) const {}
   template <typename Container>
   void permute_cols(const Container&) const {}
};

template <typename Logger>
class TransposedLogger : public Logger {
protected:
   TransposedLogger();
   ~TransposedLogger();
public:
   template <typename E>
   void from_left(const SparseMatrix2x2<E>& U) const { Logger::from_right(T(U)); }
};

template <typename Logger> inline
const TransposedLogger<Logger>& transpose_logger(const Logger& l)
{
   return static_cast<const TransposedLogger<Logger>&>(l);
}

template <typename E, bool inverse_companions>
class HNF_companion_logger {
protected:
   SparseMatrix<E> *L, *R;
public:
   // U is always unimodular, only the sign of det(U) can vary
   static
   bool det_pos(const SparseMatrix2x2<E>& U)
   {
      return U.a_ii*U.a_jj > U.a_ij*U.a_ji;
   }

   static
   SparseMatrix2x2<E> inv(const SparseMatrix2x2<E>& U)
   {
      return det_pos(U) ? SparseMatrix2x2<E>(U.i, U.j, U.a_jj, -U.a_ij, -U.a_ji, U.a_ii)
                        : SparseMatrix2x2<E>(U.i, U.j, -U.a_jj, U.a_ij, U.a_ji, -U.a_ii);
   }

   static
   SparseMatrix2x2<E> inv(const Transposed< SparseMatrix2x2<E> >& U)
   {
      return det_pos(U) ? SparseMatrix2x2<E>(U.i, U.j, U.a_jj, -U.a_ji, -U.a_ij, U.a_ii)
                        : SparseMatrix2x2<E>(U.i, U.j, -U.a_jj, U.a_ji, U.a_ij, -U.a_ii);
   }
public:
   HNF_companion_logger(SparseMatrix<E> *Rarg) : R(Rarg) {}

   template <typename Matrix>
   void from_right(const Matrix& U) const
   {
      if (inverse_companions) R->multiply_from_left(inv(U));
      else R->multiply_from_right(U);
   }

   template <typename Container>
   void permute_cols(const Container& perm) const
   {
      if (inverse_companions) R->permute_rows(entire(perm));
      else R->permute_cols(entire(perm));
   }
};

template <typename Matrix, typename CompanionLogger>
int hermite_normal_form_steps(Matrix& M, CompanionLogger& Logger
#if POLYMAKE_DEBUG
                            , pm::SparseMatrixStatistics<typename Matrix::element_type>& stat,
                            bool do_dump, const char *line_name
#endif
                            )
{
   const bool Logger_dummy=pm::derived_from<CompanionLogger, dummy_companion_logger>::value;
   typedef typename Matrix::element_type E;

   // These are working variables in the following loops,
   // but they shouldn't be created and destroyed all over the time
   SparseMatrix2x2<E> U;

   const int m = M.rows();
   const int n = M.cols();
   int current_row = 0;
   int start_col = 0;

   while ( current_row < m){
      typename Matrix::row_type::iterator e = M.row(current_row).begin(); // FIXME: Start at start_col;
      if(*e == 0){
         do{++e} while((*e == 0) && !e.at_end());
         // FIXME: Switch the right column to front.
      }

      if((*e == 0) && e.at_end()){ 
         ++current_row; continue;
      }
      
      for(typename Matrix::row_type::iterator wt = M.row(current_row).begin(); !wt.at_end()){
         if(*wt!=0){
            U_i = current_row;
            U_j = e.index();
            egcd = ext_gcd(*e, *wt); // FIXME: What is this?
            U.a_ii = egcd.p;
            U.a_ji = egcd.q;
            U.a_ij = egcd.k2;
            U.a_jj = -egcd.k1;
            
            M.multiply_from_right(U);
            Logger.from_right(U);
         }
      }
      ++start_col;
      if(start_col == n){
         break;
      }
   }
   return start_col;
}

template <typename E, typename CompanionLogger>
int hermite_normal_form(SparseMatrix<E>& M,
                      const CompanionLogger& Logger)
{
   const bool Logger_dummy=pm::derived_from<CompanionLogger, dummy_companion_logger>::value;

#if POLYMAKE_DEBUG
   const bool do_dump=getenv("SMITH_DUMP");
   if (do_dump) cout << "hermite_normal_form(initial):\n" << std::setw(6) << M;

   pm::SparseMatrixStatistics<E> stat;
   stat.gather(M);
   cout << "hermite_normal_form(initial statistics):\n" << stat;

   while (hermite_normal_form_steps(M, Logger , stat, do_dump, "row") < M.rows() &&
          hermite_normal_form_steps(T(M), transpose_logger(Logger) , stat, do_dump, "col") < M.cols()) ;

   cout << "hermite_normal_form(final statistics):\n" << stat << endl;
#else
   while (hermite_normal_form_steps(M, Logger) < M.rows() &&
          hermite_normal_form_steps(T(M), transpose_logger(Logger)) < M.cols()) ;
#endif
   int rank=0;
   Array<int> r_perm(strict_diagonal ? M.rows() : 0),
              c_perm(strict_diagonal ? M.cols() : 0);
   Array<int>::iterator rp=r_perm.begin(), rpe=r_perm.end(),
                        cp=c_perm.begin(), cpe=c_perm.end();


   return rank;
}


/// Compute the compact respresentation of the Hermite normal form, without companion matrices.
/// Input matrix M is corrupted during the computations.
/// @param[out] torsion list of diagonal elements of HNF not equal 1 with multiplicities.
/// @return rank of M.
template <typename E> inline
int hermite_normal_form_only(SparseMatrix<E>& M )
{
   int rank=hermite_normal_form(M, dummy_companion_logger(), False());
   return rank;
}

/// Complete result of computation of Hermite normal form.
template <typename E>
class HermiteNormalForm :
   public GenericStruct<HermiteNormalForm<E> > {
public:
   typedef SparseMatrix<E> matrix_type;

   DeclSTRUCT( DeclTemplFIELD(form, matrix_type)                // input matrix converted to the normal form
               DeclTemplFIELD(right_companion, matrix_type)     // form = left_companion * input * right_companion (inverted call)
               DeclTemplFIELD(rank, int) );                     // rank of form
};

/// Compute the Hermite normal form and companion matrices.
/// @param inverse_companions if true: result.form = result.left_companion * M * result.right_companion
///                           if false: M = result.left_companion * result.form * result.right_companion
template <typename Matrix, typename E> inline
HermiteNormalForm<E>
hermite_normal_form(const GenericMatrix<Matrix, E>& M,
                  typename enable_if<bool, std::numeric_limits<E>::is_integer>::type inverse_companions=false)
{
   HermiteNormalForm<E> res;
   res.form=M;
   res.right_companion=unit_matrix<E>(M.cols());
   if (inverse_companions)
      res.rank=hermite_normal_form(res.form, HNF_companion_logger<E, false>(&res.right_companion), True());
   else
      res.rank=hermite_normal_form(res.form, HNF_companion_logger<E, true>(&res.right_companion), True());
   return res;
}

}
}
namespace polymake { namespace common {

using pm::HermiteNormalForm;
using pm::hermite_normal_form;
using pm::hermite_normal_form_only;

}
}

#endif // POLYMAKE_SMITH_NORMAL_FORM_H

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
