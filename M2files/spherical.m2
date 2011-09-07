--  Chow quotient of {non-degenerate conics} \subseteq \P^5
--  under the action of the two-dim, maximal torus of PGL(3)
--
-------------------------------------------------------------------------
restart
loadPackage "Polyhedra";
loadPackage "PPDivisor";
e1 = transpose matrix {{1,0,0,0,0,0}};
e2 = transpose matrix {{0,1,0,0,0,0}};
e3 = transpose matrix {{0,0,1,0,0,0}};
e4 = transpose matrix {{0,0,0,1,0,0}};
e5 = transpose matrix {{0,0,0,0,1,0}};
e6 = transpose matrix {{0,0,0,0,0,1}};
CDual =
  posHull(e1|e2|e3|e4|e5|e6);
print rays(CDual);
C = dualCone(CDual);
print linSpace(C);
print rays(C);
-------------------------------------------------------------------------
DEG = transpose matrix {{-1,1,1}, {1,-1,1}, {1,1,-1}, {1,0,0}, {0,1,0}, {0,0,1}};
MSeq = completeSequence(DEG,"surj");
iM = MSeq#0;
pM = MSeq#1;
pN = transpose iM;
iN = transpose pM;
tN = integerSection(MSeq#1);
sM = transpose tN;
------------------------------------------------------------------------
--  Aufbau einer Gale-Sequenz
--  Bezeichnung der Abbildungen: 0 -> *A* -i-> *N* -p-> *B* -> 0
--  hat die "Schnitte"           0 <- *A* <-t- *N* <-s- *B* <- 0
p = pN;
t = tN;
    -- jetzt sollen daraus i,s berechnet werden;
m = inverse(p||t);
s = submatrix(m,,{0..(numgens target p)-1});
i = submatrix(m,,{(numgens target p)..(numgens source p)-1});
   -- (s|t)*(p||t) = sp+it = id
   -- (p||t) * (s|i) = I2, also ps=1, ti=1, pi=0, ts=0
-- print(i);
sN = s;
tM = transpose sN;
print(iN);
print(tN);
print(pN);
print(sN);
------------------------------------------------------------------------
pF87 = ppFan(C,pN,transpose(iN),transpose(tN));
raysY87 = rays pF87#0;  -- beschreibt den Faecher des torischen Chow-Quotienten
                        -- Y, auf dem der p-Divisor lebt
sigma87 = tailCone pF87#1#0;
sigma87Dual = dualCone sigma87;
print("sigma87-Erzeuger (tailcone 87):"); print(rays sigma87);
print("sigma87Dual-Erzeuger (Multigrade):"); print(rays sigma87Dual);
scan(pairs ppcoefficients(pF87#1#0), cc -> (
	vert := vertices(cc#1);
	print("ray:"); print(cc#0);
	print("coefficient:"); print(vert);
	print("Zerlegung:");
	(C,mSCL,mSCM) := (minkSummandCone(cc#1));   
	print("Minkowskikegel:");
	print(C,rays(C));
	vn := interiorVector(C) - interiorVector(C);
	v := vn;
	scan(numColumns(rays(C)), i -> (
		tray := (rays(C))_{i};
		tS := mSCL#i;
		print(tS,vertices(tS));
		v = v +tray));
	print(transpose v)));
------------------------------------------------------------------------
pF88 = ppFan(CDual,pM,transpose(iM),transpose(tM));
raysY88 = rays pF88#0;  -- beschreibt den GIT-Faecher des torischen
                        -- Chow-Quotienten
sigma88 = tailCone pF88#1#0;
sigma88Dual = dualCone sigma88;
print("sigma88-Erzeuger (tailcone 88):"); print(rays sigma88);
print("sigma88Dual-Erzeuger (Multigrade):"); print(rays sigma88Dual);
scan(pairs ppcoefficients(pF88#1#0), cc -> (
        vert := vertices(cc#1);
        print("ray:"); print(cc#0);
        print("coefficient:"); print(vert);
        print("Zerlegung:");
        (C,mSCL,mSCM) := (minkSummandCone(cc#1));
        print("Minkowskikegel:");
        print(C,rays(C));
        vn := interiorVector(C) - interiorVector(C);
        v := vn;
        scan(numColumns(rays(C)), i -> (
                tray := (rays(C))_{i};
                tS := mSCL#i;
                print(tS,vertices(tS));
                v = v +tray));
        print(transpose v)));
------------------------------------------------------------------------
F = imageFan(pM,CDual)
  -- F = pF88#0
raysF = rays F
u = (rays F)#0 + (rays F)#2
  -- Beispiel fuer ein u
P = delta(CDual,tM, pM, u)
  -- gibt das Polyeder Delta(u)
rays normalFan P
raysY87
T = hashTable(toList apply(#raysY87, i-> {raysY87#i, i}))
apply(maxCones normalFan P, C->apply(numColumns rays C, r->T#((rays C)_{r})))
apply(maxCones pF87#0, C->apply(numColumns rays C, r->T#((rays C)_{r})))


u1 = (rays (maxCones F)#2) * matrix{{1},{1},{1}} + u
P1 = delta(CDual, tM, pM, u1)
vertices P1
rays normalFan P1
apply(maxCones normalFan P1, C->apply(numColumns rays C, r->T#((rays C)_{r})))
apply(maxCones pF87#0, C->apply(numColumns rays C, r->T#((rays C)_{r})))
-------------------------------------------------------------------------
e1 = transpose matrix {{1,0,0,0,0,0}};
e2 = transpose matrix {{0,1,0,0,0,0}};
e3 = transpose matrix {{0,0,1,0,0,0}};
e4 = transpose matrix {{0,0,0,1,0,0}};
e5 = transpose matrix {{0,0,0,0,1,0}};
e6 = transpose matrix {{0,0,0,0,0,1}};
CDual = posHull(e1|e2|e3|e4|e5|e6);
DEG = transpose matrix {{-1,1,1}, {1,-1,1}, {1,1,-1}, {1,0,0}, {0,1,0}, {0,0,1}};
     
gitFanStructure(CDual, DEG)
------------------------------------------------------------------------