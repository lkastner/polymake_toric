loadPackage "Polyhedra"

powerCount = method()
powerCount(Divide, RingElement) := (f,g) -> (
     powerCount(f#0,g) - powerCount(f#1,g)
     )
powerCount(Product, RingElement):= (f,g) -> (
     sum apply(select(toList f, l->l#0==g), l->l#1)
     )

getPDivisor = method()
getPDivisor(Matrix, List) := (A,L)->(
     factors := apply(L, j->factor j);
     points := unique apply(flatten flatten apply(factors, l->{toList l#0,toList l#1}),p->p#0);
     <<factors<<endl;
     <<points<<endl;
     definingVectors := select(apply(points, p->{apply(factors, l->powerCount(l,p)),p}), v-> v#1!=-1);
     --v := apply(L, l->sum degree l);
     --definingVectors = flatten {definingVectors, {{-v,1/t}}};
     --<< v << endl;
     << definingVectors << endl;
     apply(definingVectors, v -> {intersection(-A,transpose matrix{v#0}),v#1})
     )

evaluate = method()
evaluate(List, Matrix) := (L, m) -> (
     apply(L, l -> {((transpose vertices minFace (m, l#0))*m)_(0,0), l#1})
     )


end

restart
load "p1algorithm.m2"

A = QQ[x,y]
eqmat = matrix {{1,1,0,0},{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,1,1},{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,1}}
f2 = -(x/y)^2+(x/y)
f3 = 2*(x/y)^3-3*(x/y)^2+(x/y)
f4 = -6*(x/y)^4+12*(x/y)^3-7*(x/y)^2+(x/y)


L = {f2,f2,f2,f2,f2,f2,f3,f3,f3,f3,f4}

PD = getPDivisor(eqmat,L)


evaluate(PD,transpose matrix{{1,1,0,0}})

rayList = unique flatten apply(PD, p-> rays normalFan p#0)
verticesList = apply(PD, p->vertices p#0)
