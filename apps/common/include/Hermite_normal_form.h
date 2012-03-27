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

#ifndef POLYMAKE_HERMITE_NORMAL_FORM
#define POLYMAKE_HERMITE_NORMAL_FORM

#include "polymake/SparseMatrix.h"
#include "polymake/Bitset.h"
#include "polymake/Array.h"
#include "polymake/linalg.h"
#include "polymake/numerical_functions.h"
#include "polymake/list"
#include "polymake/GenericStruct.h"

namespace pm {

class dummy_companion_logger {
public:
   template <typename E>
   void from_right(const SparseMatrix2x2<E>&) const {}
   template <typename E>
   void from_left(const SparseMatrix2x2<E>&) const {}
   template <typename Container>
   void permute_rows(const Container&) const {}
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
   void from_right(const SparseMatrix2x2<E>& U) const { Logger::from_left(T(U)); }
   template <typename E>
   void from_left(const SparseMatrix2x2<E>& U) const { Logger::from_right(T(U)); }
};

template <typename Logger> inline
const TransposedLogger<Logger>& transpose_logger(const Logger& l)
{
   return static_cast<const TransposedLogger<Logger>&>(l);
}

template <typename E, bool inverse_companions>
class SNF_companion_logger {
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
   SNF_companion_logger(SparseMatrix<E> *Larg, SparseMatrix<E> *Rarg) : L(Larg), R(Rarg) {}

   template <typename Matrix>
   void from_right(const Matrix& U) const
   {
      if (inverse_companions) R->multiply_from_left(inv(U));
      else R->multiply_from_right(U);
   }

   template <typename Matrix>
   void from_left(const Matrix& U) const
   {
      if (inverse_companions) L->multiply_from_right(inv(U));
      else L->multiply_from_left(U);
   }

   template <typename Container>
   void permute_rows(const Container& perm) const
   {
      if (inverse_companions) L->permute_cols(entire(perm));
      else L->permute_rows(entire(perm));
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
   E pivot_elem=one_value<E>(),
              g=one_value<E>();
   SparseMatrix2x2<E> U;

   int r=0, c=0, skipped=0;
   const int R=M.rows();
   while (r<R) {
      bool can_reduce=true, can_eliminate=false;
      typename Matrix::row_type::iterator e=M.row(r).begin();
      if (e.at_end()  ||  M.row(r).size()==1 && M.col(e.index()).size()==1) {
         ++r; ++skipped; continue;
      }
      skipped=0;
      g=gcd(M.row(r));
      do {
         if (abs_equal(g, *e)) {
            can_reduce=false;
            if (is_one(g) || g == gcd(M.col(e.index()))) {
               can_eliminate=true;
               c=e.index();
               pivot_elem=*e;
               break;
            }
         }
         ++e;
      } while (!e.at_end());

      if (can_reduce) {
         e=M.row(r).begin();
         pivot_elem=*e;
         c=e.index();
         for (++e; !e.at_end(); ++e) {
            ExtGCD<E> x = ext_gcd(pivot_elem, *e);
            if (!is_zero(x.q)) {
               if (!is_zero(x.p)) {
                  U.i=c;                    U.j=e.index();
                  U.a_ii = -x.k2;           std::swap(U.a_ij, x.p);
                  std::swap(U.a_ji, x.k1);  std::swap(U.a_jj, x.q);
                  M.multiply_from_right(U);
                  Logger.from_right(U);
               }
               pivot_elem=*e;
               c=e.index();
               if (g==x.g) break;
            }
         }
         can_eliminate= is_one(g) || g==gcd(M.col(c));

#if POLYMAKE_DEBUG
         stat.gather(M);
         if (do_dump) cout << "hermite_normal_form(reducing " << line_name << " " << r << " to " << g << " ):\n" << std::setw(6) << M;
#endif
      }

      if (can_eliminate) {
         if (!Logger_dummy) {
            U.i=r;  U.a_ii=one_value<E>();  U.a_jj=one_value<E>();  U.a_ij=zero_value<E>();
         }
         int next_r=-1;
         for (typename Matrix::col_type::iterator e=M.col(c).begin(); !e.at_end(); ) {
            if ((U.j=e.index()) == r) { ++e; continue; }
            if (next_r<0) next_r=U.j;
            if (abs_equal(pivot_elem, *e)) {
               if (pm::sign(pivot_elem)==pm::sign(*e)) {
                  if (!Logger_dummy) U.a_ji=-one_value<E>();
                  ++e;
                  M.row(U.j) -= M.row(r);
               } else {
                  if (!Logger_dummy) U.a_ji=one_value<E>();
                  ++e;
                  M.row(U.j) += M.row(r);
               }
            } else {
               U.a_ji=-div_exact(*e,pivot_elem);
               ++e;
               M.row(U.j) += M.row(r) * U.a_ji;
            }
            Logger.from_left(U);
         }
         if (!Logger_dummy) {
            U.i=c; U.a_ji=zero_value<E>();
         }
         for (typename Matrix::row_type::iterator e=M.row(r).begin(); !e.at_end(); ) {
            if ((U.j=e.index())==c) { ++e; continue; }
            if (!Logger_dummy) {
               U.a_ij=-div_exact(*e,pivot_elem);
               Logger.from_right(U);
            }
            M.row(r).erase(e++);
         }

#if POLYMAKE_DEBUG
         stat.gather(M);
         if (do_dump) cout << "hermite_normal_form(eliminating " << line_name << " " << r << " [" << c << "] ):\n" << std::setw(6) << M;
#endif
         if (next_r>=0) r=next_r;
         else ++r;
      } else {
         ++r;
      }
   }
   return skipped;
}

template <typename E>
void compress_torsion(std::list< std::pair<E,int> >& torsion)
{
   for (typename std::list< std::pair<E,int> >::iterator t=torsion.begin(), t_end=torsion.end(); t != t_end; ++t) {
      t->second=1;
      typename std::list< std::pair<E,int> >::iterator t2=t;  ++t2;
      for (;;) {
         if (t2 == t_end) return;
         if (t->first == t2->first) {
            ++t->second;
            t2=torsion.erase(t2);
         } else {
            break;
         }
      }
   }
}

/// Compute the compact respresentation of the Hermite normal form, without companion matrices.
/// Input matrix M is corrupted during the computations.
/// @param[out] torsion list of diagonal elements of SNF not equal 1 with multiplicities.
/// @return rank of M.
template <typename E> inline
int hermite_normal_form_only(SparseMatrix<E>& M, std::list< std::pair<E,int> >& torsion)
{
   int rank=hermite_normal_form(M, torsion, dummy_companion_logger(), False());
   compress_torsion(torsion);
   return rank;
}

/// Complete result of computation of Hermite normal form.
template <typename E>
class HermiteNormalForm :
   public GenericStruct<HermiteNormalForm<E> > {
public:
   typedef SparseMatrix<E> matrix_type;
   typedef std::list< std::pair<E,int> > torsion_type;

   DeclSTRUCT( DeclTemplFIELD(form, matrix_type)                // input matrix converted to the normal form
               DeclTemplFIELD(left_companion, matrix_type)      // input = left_companion * form * right_companion  OR
               DeclTemplFIELD(right_companion, matrix_type)     // form = left_companion * input * right_companion (inverted call)
               DeclTemplFIELD(torsion, torsion_type)            // list of torsion coefficients extracted from the diagonal of form
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
   res.left_companion=unit_matrix<E>(M.rows());
   res.right_companion=unit_matrix<E>(M.cols());
   if (inverse_companions)
      res.rank=hermite_normal_form(res.form, res.torsion, SNF_companion_logger<E, false>(&res.left_companion, &res.right_companion), True());
   else
      res.rank=hermite_normal_form(res.form, res.torsion, SNF_companion_logger<E, true>(&res.left_companion, &res.right_companion), True());
   compress_torsion(res.torsion);
   return res;
}

}
namespace polymake {

using pm::HermiteNormalForm;
using pm::hermite_normal_form;
using pm::hermite_normal_form_only;

}

#endif // POLYMAKE_SMITH_NORMAL_FORM_H

// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:
