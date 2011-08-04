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
     --<< A << endl;
     arrows := flatten apply(A, p -> {{toricGlobalSections(rays,lb#(p#1)-lb#(p#0)),(p#0,p#1)},{toricGlobalSections(rays,lb#(p#0)-lb#(p#1)),(p#1,p#0)}});
     arrows = select(arrows, o -> #(o#0) >0);
     arrows = flatten apply(arrows, a -> apply(a#0, l-> {l, a#1}));
     (n, apply(interred(n, arrows), a -> a#1))
     )

interred = method();
interred(ZZ, List) := (n,L) ->(
     --<< L << endl;
     sources := apply(n, i-> select(L, l-> l#1#0 == i));
     targets := apply(n, i-> select(L, l-> l#1#1 == i));
     --<< sources << endl << targets << endl;
     eliminators := flatten flatten apply(n, k ->
     apply(sources#k, s-> apply(targets#k, t -> {s#0+t#0, (t#1#0, s#1#1)}))
     );
     select(L, l -> #select(eliminators, e -> e#0 == l#0 and e#1 == l#1) == 0)
     )

indeg = method();
indeg(ZZ, List) := (i, L) -> #select(L, l->l#1 == i);

outdeg = method();
outdeg(ZZ, List) := (i, L) -> #select(L, l->l#0 == i);

canonicalWeight = method();
canonicalWeight(ZZ, List) := (n,L) -> apply(n, i -> outdeg(i, L)-indeg(i,L))
     

end

restart
load "quiver.m2"

-- Example 3.6 of article by Greg and Alistair.
M = matrix {{1,0,-1,0},{0,1,1,-1}}

L = {{{0,0,0,0}},{{1,0,0,0}},{{0,0,0,1}}}
L = apply(L, l->transpose matrix l)

Q = quiverOfSections(M,L)
indeg(1,Q#1)

canonicalWeight Q

-- Example 3.7
M = matrix{{1,0,-1,0},{0,1,2,-1}}
L={{{0,0,0,0}},{{1,0,0,0}},{{0,0,0,1}},{{1,0,0,1}}};
L = apply(L, l->transpose matrix l)

incidenceMatrix quiverOfSections(M,L)

-- Example 5.8
M = transpose matrix{{1,0,0},{0,1,0},{-1,-1,-1},{0,1,1},{1,0,1}}
L={{{0,0,0,0,0}},{{0,1,0,0,0}},{{0,0,1,0,0}},{{0,1,1,0,0}},{{0,0,2,0,0}},{{0,1,2,0,0}}};
L = apply(L, l->transpose matrix l)

Q = quiverOfSections(M,L)
canonicalWeight Q

-- Junk at the end.

{1,0,0}-{0,0,2}
l = (3,2)
flatten {toList (l#0:0),1,toList ((10-l#0):0)}
getFan(10,{(0,2),(1,3),(3,1),(1,3),(2,1),(5,3),(9,1),(8,1),(9,8)})

L=1..5
subsets(5,2)
