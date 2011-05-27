loadPackage "Polyhedra"

evaluate := method();
evaluate(List, Matrix) := (L, v) -> (
     apply(L, l -> {((transpose vertices minFace (m, l#0))*m)_(0,0), l#1})
     )
	  
globalSections := method();
globalSections(List, Ring) := (L, R) -> (
     x := (vars R)_(0,0);
     product apply(L, l -> {(x-l#1),(l#0)})
     )

algorithmA1 := method();
algorithmA1(List, Ring) := (L, R) ->(
     ms := sum apply(L, l-> l#0);
     omega := normalFan ms;
     raylist := apply(rays omega, ray -> evaluate(L, ray));
)     

denominator promote(raylist#0#0#1, QQ)
ms
rays omega
vertices ms
tailCone C
C = hypercube(3)
vertices C
m = transpose matrix {{1,0,0}}
((transpose vertices minFace (m, C))*m)_(0,0)
L = {{C,1},{C,2},{C,3}}
globalSections(evaluate(L,m), frac(A))

A = QQ[t]
R = Ring({t-1,t-2})

x := (vars A)_(0,0)
x^2
1/(x-3)^2

A1 = QQ[t]
QA1 = frac A1
vars QA1

A2 = QQ[y]
QA2 = frac A2
f = map(QA1, QA2, {t-5})
isInjective f
matrix{{y-5}}
