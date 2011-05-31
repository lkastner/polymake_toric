loadPackage "Polyhedra"

evaluate := method();
evaluate(List, Matrix) := (L, v) -> (
     apply(L, l -> {((transpose vertices minFace (m, l#0))*m)_(0,0), l#1})
     )
	  
globalSections := method();
globalSections(List) := (L) -> (
     	  product apply(L, l-> (l#1)^(ceiling(-l#0)))
     )

algorithmA1 := method();
algorithmA1(List, Ring) := (L, R) ->(
     t := (vars R)_(0,0);
     A := R[x,y];
     ms := sum apply(L, l-> l#0);
     omega := normalFan ms;
     raylist := rays omega;
     raylist = apply(raylist, r-> {r, evaluate(L,r)});
     raylist = apply(raylist, r -> {r#0, r#1, mult r#1});
     gL := apply(raylist, r -> globalSections evaluate(L, (r#2)*(r#0))*x^((r#2)*((r#0)_(0,0)))*y^((r#2)*((r#0)_(1,0))));
     gL = flatten {gL, t};
     degs := apply(raylist, r-> flatten entries ((r#2)*(r#0)));
     if #degs < 2 then error "not enough degrees.";
     n := #degs;
     if not (det (hermite transpose matrix degs)_{n-2,n-1})^2==1 then (
	       gL = flatten {gL, globalSections(evaluate(L,matrix {{1},{0}}))*x};
	       gL = flatten {gL, globalSections(evaluate(L,matrix {{0},{1}}))*x};
	  );
     gL
)

mult := method()
mult(List):= L ->(
     	  if not all(L, l-> instance(l#0,ZZ)) then (
	       lcm apply(L, l-> denominator promote(l#0,QQ))
	       ) else (
	       1
	       )     
     )

         
A = QQ[t]
eqmat = -matrix {{4,0},{3,1},{2,2},{1,3},{0,4}}
v1 = transpose matrix {{0,1,0,1,3}}
v2 = transpose matrix {{1,0,0,1,3}}
v3 = transpose matrix {{1,0,1,0,1}}
v4 = transpose matrix {{3,1,0,0,1}}
v5 = transpose matrix {{3,1,0,1,0}}
P1 = intersection(eqmat, v1)
P2 = intersection(eqmat, v2)
P3 = intersection(eqmat, v3)
P4 = intersection(eqmat, v4)
P5 = intersection(eqmat, v5)
L = {{P1,t-2},{P2,t-1},{P3,t},{P4,t+1},{P5,t+2}}

m = matrix {{0},{4}}
evaluate(L,m)

gL = algorithmA1(L,A)
gL#0

rays P
