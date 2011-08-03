loadPackage "Polyhedra"

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

isCycleFree = method();
isCycleFree(ZZ,List) := (n,L) -> (
     
     )

toricGlobalSections = method();
toricGlobalSections(Matrix, Matrix) := (rays, coeffs) -> (
     latticePoints intersection(-transpose rays,coeffs)
     )

quiverOfSections = method();
quiverOfSections(Matrix, List) := (rays, lb) -> (
     n := #lb;
     A := subsets(n,2);
     << A << endl;
     arrows := flatten apply(A, p -> {{toricGlobalSections(rays,lb#(p#1)-lb#(p#0)),(p#0,p#1)},{toricGlobalSections(rays,lb#(p#0)-lb#(p#1)),(p#1,p#0)}});
     arrows = select(arrows, o -> #(o#0) >0);
     arrows = flatten apply(arrows, a -> apply(a#0, l-> {l, a#1}));
     indec := {};
     for cs from 0 to n-1 do (
	  for ts from 0 to n-1 do (
	       if not cs == ts then (
		    ct := select(arrows, a -> a#1#0 == cs and a#1#1 == ts);
		    <<ct<<endl;
		    indec = flatten {indec, ct};
		    
			 
		    )
	       )
	  );
     indec
     )

end

restart
load "quiver.m2"

-- Example of article by Greg and Alistair.
M = matrix {{1,0,-1,0},{0,1,1,-1}}

L = {{{0,0,0,0}},{{1,0,0,0}},{{0,0,0,1}}}
L = apply(L, l->transpose matrix l)

quiverOfSections(M,L)



-- Junk at the end.

{1,0,0}-{0,0,2}
l = (3,2)
flatten {toList (l#0:0),1,toList ((10-l#0):0)}
getFan(10,{(0,2),(1,3),(3,1),(1,3),(2,1),(5,3),(9,1),(8,1),(9,8)})

L=1..5
subsets(5,2)
