from sage.rings.polynomial.multi_polynomial_libsingular import MPolynomialRing_libsingular as MPR
from sage.groups.group import AbelianGroup as AGRP

from sage.structure.parent_gens import ParentWithGens
import sage.misc.latex
from sage.rings.integer_ring import ZZ
from sage.rings.polynomial.polydict import PolyDict
from sage.misc.latex import latex_variable_name

from sage.rings.polynomial.polynomial_ring_constructor import PolynomialRing as PR

from listManagement import unique

def multidegree(f):
	R=f.parent()
	if not isinstance(f.parent(), MultigradedRing):
		raise TypeError, "Containing ring has to be multigraded."
	A = R.grading
	w = R.variable_weights
	M = f.monomials()
	result = []
	for i in range(0,len(M)): 
		deg=A.one()
		dlist = M[i].degrees()
		for j in range(0,R.ngens()): 
			deg = deg *  w[j]**dlist[j]
		result.append(deg)
	return result

def is_homogeneous(f):
	degree = multidegree(f)
	if len(unique(degree))!= 1:
		return False
	return True

def testrun():
	A = AbelianGroup(3)
	R = MultigradedRing(QQ, 3, 'z', "dp", A, A.gens())
	x, y, z = R.gens()
	f = x**2 + 4*x*y + z
	mf = multidegree(f)
	print mf
	print unique(mf)
	is_homogeneous(f)


class MultigradedRing(MPR):
	def __init__(self, base_ring, n, names, order, grp, weights):
		if len(weights) != n:
			 raise IndexError, "Number of weights has to agree with number of variables."
		for i in range(0,len(weights)): 
			if not isinstance(weights[i],AbelianGroupElement):
				raise TypeError, "Variable weights have to be group elements."
			if not weights[i].parent() == grp:
				raise TypeError, "Variable weights have to be contained in the grading group."
		MPR.__init__(self, base_ring, n, names, order)
		self.grading = grp
		self.variable_weights = weights	
