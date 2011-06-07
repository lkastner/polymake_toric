loadPackage "Polyhedra"

findInteriorLatticeBasis = method();
findInteriorLatticeBasis(Cone) := C ->(
     M := rays C;
     (D,R) := modifiedHermite M;
     
     )

modifiedHermite = method();
modifiedHermite(Matrix) := M -> (
     (D,R) := hermite(M,ChangeMatrix=>true);
     n := numRows D;
     m := numColumns D;
     --<<m<<" "<<n<<endl;
     for i from 0 to n-1 do (
     	  C := mutableMatrix map(ZZ^m,ZZ^m,1);
	  for j from m-i to m-1 do (
	       --C_(n-i-1,j)=-1;
	       if D_(n-i-1,j)%D_(n-i-1,m-i-1)!=0 then C_(m-i-1,j) = -1-(D_(n-i-1,j)-(D_(n-i-1,j)%D_(n-i-1,m-i-1)))//D_(n-i-1,m-i-1);
	       );
	  --<<C<<endl;
	  R = R*(matrix C);
	  D = D*(matrix C);
     	  );
     (D,R)
     )


C = posHull map(ZZ^3,ZZ^3,1)
C = posHull transpose matrix {{12,5,3},{4,25,6},{6,2,7},{-6,6,4}}
rays C
M = rays C
hermite(M, ChangeMatrix=>true)
g = matrix {{0,13,36,1},{0,0,10,9},{0,0,0,7}}
hermite g
(A,B)= modifiedHermite hermite(g, ChangeMatrix=>true)
det B

(D,R,L) = smithNormalForm rays C
R*(rays C)*L
R*(rays C)
