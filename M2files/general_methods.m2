loadPackage "Polyhedra"

findInteriorLatticeBasis = method();
findInteriorLatticeBasis(Cone) := C ->(
     M := rays C;
     (D,R,L) := smithNormalForm M;
     )

C = posHull map(ZZ^3,ZZ^3,1)
C = posHull matrix {{1,5,3},{4,5,6},{5,6,7}}
rays C
(D,R,L) = smithNormalForm rays C
R*(rays C)*L
R*(rays C)
