from sage.rings.polynomial.multi_polynomial_libsingular import MPolynomialRing_libsingular as MPR
from sage.groups.group import AbelianGroup as AGRP

from sage.structure.parent_gens import ParentWithGens
import sage.misc.latex
from sage.rings.integer_ring import ZZ
from sage.rings.polynomial.polydict import PolyDict
from sage.misc.latex import latex_variable_name

from sage.rings.polynomial.polynomial_ring_constructor import PolynomialRing as PR

class MultigradedRing(MPR):
	def __init__(self, base_ring, n, names, order, grp, weights):
		if weights.pop() != n:
			 raise IndexError, "Number of weights has to agree with number of variables."
		MPR.__init__(self, base_ring, n, names, order)
		self.grp = grp	
