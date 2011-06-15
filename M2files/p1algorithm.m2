loadPackage "Polyhedra"

getPDivisor := method()
getPDivisor(Matrix, List) := (A,L)->(
     factors := apply(L, j->factor j);
     points := unique apply(flatten apply(factors, f-> toList f), l->l#0);
     definingVectors := select(apply(points, p->{apply(factors, l->powerCont(l,p)),p}), v-> v#1!=-1);
     v := apply(L, l->sum degree l);
     definingVectors = flatten {definingVectors, {{-v,1/t}}};
     << v << endl;
     apply(definingVectors, v -> {intersection(-A,transpose matrix{v#0}),v#1})
     )

powerCont := method()
powerCont(Divide, RingElement) := (f,g) -> (
     powerCont(f#0,g) - powerCont(f#1,g)
     )
powerCont(Product, RingElement):= (f,g) -> (
     sum apply(select(toList f, l->l#0==g), l->l#1)
     )

evaluate := method();
evaluate(List, Matrix) := (L, m) -> (
     apply(L, l -> {((transpose vertices minFace (m, l#0))*m)_(0,0), l#1})
     )



A = QQ[t]
eqmat = matrix {{1,1,0,0},{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,1,1},{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,1}}
f2 = -t^2+t
f3 = 2*t^3-3*t^2+t
f4 = -6*t^4+12*t^3-7*t^2+t
L = {f2,f2,f2,f2,f2,f2,f3,f3,f3,f3,f4}
PD = getPDivisor(eqmat,L)
apply(PD, p->rays p#0)
evaluate(PD,transpose matrix {{1,1,1,0}})
sum degree f2
denominator (1/t)
denominator t
class(1/t)
1/(t-t^2)
powerCont(f2,(1/t))
