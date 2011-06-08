restart
loadPackage "Polyhedra"
loadPackage ("IntegralClosure", Reload=>true)

evaluate := method();
evaluate(List, Matrix) := (L, m) -> (
     apply(L, l -> {((transpose vertices minFace (m, l#0))*m)_(0,0), l#1})
     )
	  
globalSections := method();
globalSections(List) := (L) -> (
     	  product apply(L, l-> (l#1)^(floor l#0))
     )

algorithmA1 := method();
algorithmA1(List, Ring) := (L, R) ->(
     t := (vars R)_(0,0);
     A := R[x,y];
     ms := sum apply(L, l-> l#0);
     omega := normalFan ms;
     raylist := rays omega;
     raylist = apply(raylist, r-> {r, evaluate(L,r)});
     raylist = apply(raylist, r -> {r#0, r#1, mult (r#1)});
     << raylist << endl;
     gL := apply(raylist, r -> globalSections evaluate(L, (r#2)*(r#0))*x^((r#2)*((r#0)_(0,0)))*y^((r#2)*((r#0)_(1,0))));
     gL = flatten {gL, t};
     degs := apply(raylist, r-> flatten entries ((r#2)*(r#0)));
     if #degs < 2 then error "not enough degrees.";
     n := #degs;
     if not (det (hermite transpose matrix degs)_{n-2,n-1})^2==1 then (
	       gL = flatten {gL, globalSections(evaluate(L,matrix {{1},{0}}))*x};
	       gL = flatten {gL, globalSections(evaluate(L,matrix {{0},{1}}))*x};
	  );
     {gL, A}
)

mult := method();
mult(List):= L ->(
     	  if not all(L, l-> instance(l#0,ZZ)) then (
	       lcm apply(L, l-> denominator promote(l#0,QQ))
	       ) else (
	       1
	       )     
     )

normalize := method();
normalize(List, Ring):=(L,R)->(
     n:= #L;
     P := QQ[vars(0..(n-1))];
     f := map(R,P,L);
     I := kernel f;
     integralClosure (P/I)
     )


eqmat = - matrix {{1,0},{0,1},{1,1}}
v = transpose matrix {{1,1,1}}
D = intersection(eqmat,v)
vertices D         
rays D
z_1..z_10

A = QQ[t]
L = {{D,t}}
gL = algorithmA1(L,A)
gL#0
gL#1
normalize(gL#0, gL#1)

R = QQ[r,s,t,u]
f = map(gL#1, R, gL#0)

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

restart
A = QQ[t,b1,b2,b3,b4]
P = QQ[(x_0..x_10)]
P
vars P
f2=-t^2+t
f3=2*t^3-3*t^2+t
f4=-6*t^4+12*t^3-7*t^2+t
h = map(A,P,{f2*b1*b2,f2*b1*b3,f2*b1*b4,f2*b2*b3,f2*b2*b4,f2*b3*b4,f3*b1*b2*b3,f3*b1*b2*b4,f3*b1*b3*b4,f3*b2*b3*b4,f4*b1*b2*b3*b4})
I = kernel h
#I
I_0
loadPackage("IntegralClosure", Reload=>true)
icFractions (P/I)


eqmat = matrix {{1,1,0,0},{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,1,1},{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,1}}
v2 = transpose matrix {{1,1,1,1,1,1,0,0,0,0,0}}
v3 = transpose matrix {{0,0,0,0,0,0,1,1,1,1,0}}
v4 = transpose matrix {{0,0,0,0,0,0,0,0,0,0,1}}
P2 = intersection(-eqmat,-v2)
vertices P2
P3 = intersection(-eqmat,-v3)
vertices P3
P4 = intersection(-eqmat,-v4)
rays P4
vertices P4
A = QQ[t]
f2 = -t^2+t
f3 = 2*t^3-3*t^2+t
f4 = -6*t^4+12*t^3-7*t^2+t
f3/f4
promote(f2,frac A)
L = {{P2,promote(f2,frac A)},{P3,f3/f2},{P4,f4/(f3*f2)}}
evaluate(L,transpose matrix {{1,1,1,1}})
globalSections(evaluate(L, transpose matrix {{0,1,0,1}}))
globalSections(evaluate(L, transpose matrix {{1,1,0,1}}))
globalSections(evaluate(L, transpose matrix {{1,1,1,1}}))
