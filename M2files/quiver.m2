incidenceMatrix = method();
incidenceMatrix(ZZ, List) := (n, L) -> (
     transpose matrix apply(L, l -> flatten {toList (l#0:0),1,toList ((n-l#0-1):0)}-flatten {toList (l#1:0),1,toList ((n-l#1-1):0)})
     )

getFan = method();
getFan(ZZ, List) := (n,L) -> (
     Cir := gens kernel incidenceMatrix(n, L);
     << hermite Cir << endl;
     rays := entries Cir;
     )

{1,0,0}-{0,0,2}
l = (3,2)
flatten {toList (l#0:0),1,toList ((10-l#0):0)}
getFan(10,{(0,2),(1,3),(3,1),(1,3),(2,1),(5,3),(9,1),(8,1),(9,8)})
