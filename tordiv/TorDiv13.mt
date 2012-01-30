restart;
TorDiv13 := module()
export
#
#
# Functions on lattices:
#
   cols2matrix,
   completeseq,
   dualseq,
   ihermiterowops,
   ihermitecolops,
   intcontains,
   intersectlattices,
   intimage,
   intiscontained,
   intkernel,
   intpreimage,
   intprojection,
   intsection,
   isprimitive,
   issurjective,
   latticebasis,
   matrix2cols,
   primitivespan,
#
# Functions on polyhedra:
#
   bunch,
   bunchcones,
   bunchprojection,
   bunch2fan,
   cocoref,
   imagefan,
   covcoll,
   dualface,
   fan2bunch,
   freecovering,
   intersectrelint,
   isprojectedface,
   isstandard,
   pairwiseintersectrelint,
   relintcontains,
   relintiscontained,
#
# Functions on toric varieties
#
   amplecone,
   canonclass,
   cartierdiv,
   coxconstr,
   effectivecone,
   isdivisorial,
   isfano,
   isgorenstein,
   isprojective,
   isquasiprojective,
   istwocomplete,
   kajiwaraconstr,
   movingcone,
   picardgroup,
   samplecone,
   twocompletion,
#
# Functions on GIT
#
   admitsgoodquot,
   chamber,
   gitfan,
   gitlimit,
   poldiv,
   base,
   basedim,
   tailcone,
   torusdim,
   coefficients,
   slice,
   ppdivisor,
   ppfan,
   quotientfan,
   semistablepoints,
   weight2bunch,
#
# Examples 
#
   cutpyramid,
   freebentcube,
   hirzebruch;
#
# Local procedures
#
local
   bunchcheck,
   bunching,
   dimmin,
   dimsort,
   listlistmatrixcheck,
   listlistmatrixoutput,
   listlistmatrix2listlist,
   listlistmatrix2matrix,
   integerentriescheck,
   isbunchmaximal,
   groessere,
   mincones,
   negat,
   nopssort,
   coneslistcheck,
   basevector,
   optioncheck,
   posorthantface,
   projectcones,
   listvector2index,
   liftcone,
   reduc,
   weightcone,
   refinecones,
   lookup,
   poldiv_type,
   poldiv_print,
   setup,
   cleanup;
#
# Module Options
#
option
   package,
   load = setup,
   unload = cleanup;

#
# Definition of local procedures
#
setup := proc()
global `type/BUNCH`,`print/BUNCH`, `type/POLDIV`,`print/POLDIV`:

#
  printf(cat("TorDiv, Version 1.2, (C) 2006 by F. Berchtold, J. Hausen, M. Widmann.\n", 
             "This package is distributed under the GNU General Public License. It\n" 
             "requires the convex package by M. Franz.\n"));
#
`type/BUNCH` := proc(B)
evalb(op(1,B)=`BUNCH`):
end proc:
#
`print/BUNCH` := proc(b,Q,CL,m,k,l)
`BUNCH`(m,k,l)
end proc:
# 
protect(BUNCH):
userinfo(1, `bunch`, "new type `BUNCH` defined" );
#
`type/POLDIV` := proc() poldiv_type(args): end proc:
#
`print/POLDIV` := proc() poldiv_print(args): end proc:
#
protect(POLDIV):
userinfo(1, `poldiv`, "new type `POLDIV` defined");
#
NULL
end proc;

cleanup := proc()
global `type/BUNCH`,`print/BUNCH`, `type/POLDIV`,`print/POLDIV`:
   userinfo(1, `bunch`, "cleaning up global type `BUNCH`" ):
   unprotect(BUNCH):
   `type/BUNCH` := evaln(`type/BUNCH`):
   `print/BUNCH` := evaln(`print/BUNCH`):
   userinfo(1, `poldiv`, "cleaning up global type `POLDIV`" ):
   unprotect(POLDIV):
   `type/POLDIV` := evaln(`type/POLDIV`):
   `print/POLDIV` := evaln(`print/POLDIV`):
NULL
end proc;

bunchcheck := proc(Q::matrix,CL::list)
local i:
integerentriescheck(Q):
coneslistcheck(CL,commonambientspace):
if not issurjective(Q) then
 error "expecting a surjection as first argument":
end if:
for i to nops(CL) do
 if not isprojectedface(CL[i],Q) then
   error "some cone of the list is not a weight cone":
 end if:
end do:
if not pairwiseintersectrelint(CL) then 
  error "for some pair of cones the relative interiors do not intersect": 
end if:
if not nops(CL) = nops(mincones(CL)) then 
  error "list of cones is redundant" 
end if:
if not isbunchmaximal(Q,CL) then 
  error "list of cones allows additional compatible cones":
end if: 
end proc;

# look up an entry in a list of pairs
lookup := proc(x, L :: list, fail)
  local i, result:
  if nargs = 3 then
    result := fail:
  else
    result := FAIL:
  end if:
  for i to nops(L) do
     if evalb(x = L[i][1]) then
       result := L[i][2]:
       break:
     end if:
  end do:
  result:
end proc:

bunching := proc(A,C::list)
local Q,i, j, k, s, w, testkegel, strauss, liste, enthaelt, schneidet:
if nargs < 2 or nargs > 3 then error "wrong number of arguments" end if:
listlistmatrixcheck(A):
Q:=listlistmatrix2matrix(A):
integerentriescheck(Q):
if not issurjective(Q) then error "Projection must be surjective" end if:
for i from 1 to nops(C) do
  if not type(C[i],CONE) then error "second argument must be a list of cones" end 
if:
  if not isprojectedface(C[i],Q) then error "second argument must be a list of projected faces" end if:
end do:
if not pairwiseintersectrelint(C) then error "cones incompatible" end if:
w := linalg[coldim](Q):
s := combinat[choose]([seq(i,i=1..w)]):
strauss := C:
for j from 1 to nops(s) do
  testkegel := weightcone(s[j],Q):
  enthaelt := false:
  schneidet := true:
  for k from 1 to nops(strauss) while not enthaelt and schneidet do
    if not intersectrelint(testkegel,strauss[k]) then
      schneidet := false
    elif contains(testkegel,strauss[k]) then 
      enthaelt := true
    end if:
  end do:
  if not enthaelt and schneidet then
    liste := []:
    for k from 1 to nops(strauss) do
      if not contains(strauss[k],testkegel) then
        liste := [op(liste),strauss[k]]:
      end if:
    end do:
    strauss := [op(liste),testkegel]:
  end if:
end do:
bunch(Q,strauss):
end proc;

# triangulate, then coarsify
# input is a list of cones of full dimension, with support a
#  (not necessarily pointed) cone
refinecones := proc(IL :: list)
  local rs, c, r, triang, m, n, v, x, mcones:
  n := ambientdim(IL[1]):
  rs := []:
  mcones := []:
  for c in IL do
    for r in rays(c) do
      if not evalb(r in rs) then
        rs := [r, op(rs)]:
      end if:
    end do:
  end do:
  triang := cocoref(rs):
  for m in maximal(triang) do
    x := fullcone(n):
    v := relint(m):
    for c in IL do:
      if contains(c, v) then
        x := intersection(x, c):
      end if:
    end do:
    mcones := [op(mcones), x]:
  end do:
  fan(op(mcones)):
end proc:

dimmin := proc(C)
local M, Mj, E, T, j, min:
M:=C:
E:=[]:
while (nops(M)>0) do
  min:=`true`:
  T:=[M[1]]:
  M:=subsop(1=NULL,M):
  Mj:=[]:
  for j from 1 to nops(M) while min do
    if contains(op(T),M[j]) then 
      min := `false`:
      T := []: 
      Mj := M:
    elif not contains(M[j],op(T)) then 
      Mj := [op(Mj),M[j]] 
    end if:
  end do:
  E := [op(E),op(T)]:
  M := Mj:
end do:
E:
end proc;

dimsort := proc(CL)
local n, i, SCL, B, k:
coneslistcheck(CL,commonambientspace):
n:=ambientdim(CL[1]):
B:=array(0..n):
SCL:=[]:
for i from 0 to n do
  B[i] := []:
end do:
for i from 1 to nops(CL) do
  k := dim(CL[i]):
  B[k] := [op(B[k]),CL[i]]:
end do:
for i from 0 to n do
  if nops(B[i]) > 0 then 
    SCL := [op(SCL),B[i]] 
  end if:
end do:
SCL:
end proc;

isbunchmaximal := proc(Q::matrix,CL::list)
local indiceslist, j, testkegel, enthaelt, schneidet, k:  
indiceslist := combinat[choose]([seq(i,i=1..linalg[coldim](Q))]):
for j from 1 to nops(indiceslist) do
  testkegel := weightcone(indiceslist[j],Q):
  enthaelt := false:
  schneidet := true:
  for k to nops(CL) while not enthaelt and schneidet do
    if not intersectrelint(testkegel,CL[k]) then
      schneidet := false:
    elif contains(testkegel,CL[k]) then 
      enthaelt := true
    end if:
  end do:
  if not enthaelt and schneidet then
    return false: 
  end if:
end do:
true:
end proc;

listlistmatrixcheck := proc(B)
if not type(B,{listlist,matrix}) then 
  error "expecting a listlist or a matrix as argument" 
end if:
end proc:

integerentriescheck := proc(B)
local i,j;
if type(B,matrix) then
  for i to linalg[rowdim](B) do 
    for j to linalg[coldim](B) do
      if not type(B[i,j],integer) then 
        error "expecting integer entries" 
      end if
    end do:
  end do:
else
  for i to nops(B) do 
    for j to nops(B[i]) do
      if not type(B[i,j],integer) then 
        error "expecting integer entries" 
      end if
    end do:
  end do:
end if:
end proc:

mincones := proc(L::list)
local B, BB, C, D, Ek, i, j, k, l:
coneslistcheck(L,commonambientspace):
B := dimsort(L):
if dim(B[1][1]) = 0 then 
  return [B[1][1]] 
end if:
C := []:
while (nops(B) > 0) do
  D := dimmin(B[1]):
  C := [op(C),op(D)]:
  B := subsop(1 = NULL,B):
  for j from 1 to nops(D) do
    BB := []:
    for k from 1 to nops(B) do
      Ek := B[k]:
      B[k] := []:
      for l from 1 to nops(Ek) do
        if not contains(Ek[l],D[j]) then 
          B[k] := [op(B[k]),Ek[l]]: 
        end if:
      end do:
      if nops(B[k]) > 0 then 
        BB := [op(BB),B[k]]: 
      end if:
    end do:
    B := BB:
  end do:
end do:
C:
end proc;

negat := proc(C::CONE)
local LC, SC, NC:
LC := lineality(C):
SC := rays(C):
if SC = [] then
  NC := LC:
else
  NC := poshull(op(map(proc(v) (-1)*v end, SC))):
  NC := poshull(NC,LC):
end if:
NC:
end proc;

optioncheck := proc(optsgiven,optsallowed)
if not evalb(optsgiven subset optsallowed) then 
  error "choice of options not admissible" 
end if:
end proc:

groessere := proc(tupel,indset)
local tp, diffs, gr, i;
tp := op(tupel):
diffs := combinat[choose](indset minus {tp}):
gr := {}:
for i to nops(diffs) do:
  gr := gr union {[op({tp} union diffs[i])]}:
end do:
end proc:

nopssort := proc(L,s)
local La,i:
La := array(1..s):
for i to s do
  La[i] := []:
end do:
for i to nops(L) do
  La[nops(L[i])] := [op(La[nops(L[i])]),L[i]]:
end do:
[seq(op(La[i]),i=1..s)]:
end proc:

listlistmatrixoutput := proc(B,optsgiven)
if evalb(`matrix` in optsgiven) then
  listlistmatrix2matrix(B):
elif evalb(`list` in optsgiven) then
  listlistmatrix2listlist(B):
else
  listlistmatrix2listlist(B):
end if:
end proc:

listlistmatrix2matrix := proc(B)
local BB:
if type(B,listlist) then 
  BB := matrix(B):
  BB := linalg[transpose](BB):
else 
  BB := B:
end if:
evalm(BB):
end proc:

listlistmatrix2listlist := proc(B)
local BB:
if type(B,matrix) then 
  BB:=linalg[transpose](B):
  BB := convert(BB,listlist):
else 
  BB:=B: 
end if:
end proc:

coneslistcheck := proc()
local CL, opt, i:
CL := args[1]:
if not type (CL,list) then 
  error "expecting a list of cones" 
end if:
for i from 1 to nops(CL) do
  if not type (CL[i],CONE) then 
    error "expecting a list of cones" 
  end if:
end do:
if evalb(`commonambientspace` in {seq(args[i],i=1..nargs)}) and evalb(not nops(CL) = 1) then
  for i from 2 to nops(CL) do
    if not evalb(ambientdim(CL[i])=ambientdim(CL[1])) then 
      error "cones must lie in a common ambient space" 
    end if:
  end do:
end if:
end proc:

basevector := proc(n::integer,i::integer)
local e:
e := array(1..n,sparse):
e[i]:=1:
convert(e,list):
end proc:

posorthantface := proc(n::integer,ind::list)
local RL:
RL := map2(basevector,n,ind):
poshull(op(RL)):
end proc:

projectcones := proc(CL::{CONE,list(CONE)},P)
local B:
listlistmatrixcheck(P):
B := listlistmatrix2matrix(P):
if type(CL, CONE) then 
  image(CL,P):
else
  map(image,CL,B):
fi:
end proc;

listvector2index := proc(v::list,L::listlist)
local i:
for i to nops(L) do
  if v = L[i] then
    return(i):
  end if:
end do:
end proc:

liftcone := proc(C::CONE,n::integer,L::listlist)
local ind:
ind := map(listvector2index,rays(C),L):
posorthantface(n,ind):
end proc:

weightcone := proc(IndexList::list,Q::matrix)
local strahlen, i, C:
strahlen := []:
for i to nops(IndexList) do
  strahlen := [op(strahlen), linalg[col](Q,IndexList[i])]:
end do:
if nops(strahlen) = 0 then
  C := zerocone(linalg[rowdim](Q)):
else
  C := poshull(op(strahlen)):
end if:
C:
end proc;

reduc := proc(HL::list)
local i, j, Mbl, tc, isnew:
gc():
Mbl := []:
for i from 1 to nops(HL) do  
  tc := HL[i]:
  isnew := true:
  for j from i+1 to nops(HL) while isnew do
    if contains(tc, HL[j]) and iscontained(tc, HL[j]) then
      isnew := false:
    end if:
  end do:
  if isnew then 
    Mbl := [op(Mbl), tc]:
  end if:
end do:
Mbl:
end proc:       

#
# Definition of procedures on lattices
#

cols2matrix := proc(Li::list)
local L:
L := map(convert, Li, list):
listlistmatrix2matrix(L):
end proc:

completeseq := proc(B::{listlist,matrix},specif)
local BB:
integerentriescheck(B):
BB := listlistmatrix2matrix(B):
if specif = `inj` then
  [evalm(BB),intprojection(BB,matrix,red)]:
elif specif = `surj` then
  [intkernel(BB,matrix,red),evalm(BB)]:
else
  error "missing specification `inj` or `surj`" 
end if:
end proc:

dualseq := proc(BB)
[linalg[transpose](BB[2]),linalg[transpose](BB[1])]:
end proc:

ihermiterowops := proc(B)
local BB:
BB := listlistmatrix2matrix(B):
BB := linalg[ihermite](BB,`U`):
[evalm(BB),evalm(U)];
end proc:

ihermitecolops := proc(B)
local BB:
BB := listlistmatrix2matrix(B):
BB := ihermiterowops(linalg[transpose](BB)):
map(linalg[transpose],BB):
end proc:

intcontains := proc(A::{listlist,matrix},v::list)
local B, L, k, a:
B := listlistmatrix2listlist(A):
B := [op(B),v]:
L := intkernel(B,list):
k := nops(L[1]):
a := seq(L[j][k],j=1..nops(L)):
if igcd(a) = 1 then
  return true:
else
  return false:
end if:
end proc:

intersectlattices := proc()
local L1, L2, optsgiven, L, bas, ker, schnitt, cut:
L1 := args[1]:
L2 := args[2]:
listlistmatrixcheck(L1):
integerentriescheck(L1):
listlistmatrixcheck(L2):
integerentriescheck(L2):
optsgiven := {seq(args[i], i=3..nargs)}:
optioncheck(optsgiven, {`red`,`list`,`matrix`}):
L1 := listlistmatrix2matrix(L1):
L2 := listlistmatrix2matrix(L2):
L := linalg[augment](L1,-L2):
ker := intkernel(L,matrix):
bas := linalg[submatrix](ker,1..linalg[coldim](L1),1..linalg[coldim](ker)):
schnitt := evalm(&*(L1,bas)):
cut := ihermitecolops(schnitt)[1]:
if linalg[rank](cut) = 0 then 
  cut := [[0$linalg[rowdim](cut)]]:
else 
  cut := linalg[submatrix](cut,1..linalg[rowdim](cut),1..linalg[rank](cut)):
  cut := listlistmatrix2listlist(cut):
  if evalb(`red` in optsgiven) then   
    cut := lattice(cut,integer):
  end if:
end if:
listlistmatrixoutput(cut,optsgiven):
end proc:

intimage := proc(Ai::{listlist,matrix},Bi::{listlist,matrix})
local A, B, optsgiven, C, L;
optsgiven := {seq(args[i], i=3..nargs)}:
optioncheck(optsgiven,{`list`,`matrix`,`red`}):
A := listlistmatrix2matrix(Ai):
integerentriescheck(A):
B := listlistmatrix2matrix(Bi):
integerentriescheck(B):
C := linalg[multiply](A,B):
L := latticebasis(C,list):
if evalb(`red` in optsgiven) then      
  L := lattice(L,integer):
end if:
listlistmatrixoutput(L,optsgiven):
end proc;

intkernel := proc(Bi::{listlist,matrix})
local B, optsgiven, n, r, U:
integerentriescheck(Bi):
optsgiven := {seq(args[i], i=2..nargs)}:
optioncheck(optsgiven, {`red`,`list`,`matrix`}):
B := listlistmatrix2matrix(Bi):
n:=linalg[coldim](B):
r := linalg[rank](B):
if r = 0 then
  U := linalg[diag](1$n):
elif r = n then
  U := [[0$n]]:
else
  U := ihermitecolops(B)[2]:
  U := linalg[delcols](U,1..r):
  U := listlistmatrix2listlist(U):
  if evalb(`red` in optsgiven) then   
    U := lattice(U,integer):
  end if:
end if:
listlistmatrixoutput(U,optsgiven):
end proc;

intpreimage := proc()
local A, B, optsgiven, C, L;
A := args[1]:
B := args[2]:
listlistmatrixcheck(A):
listlistmatrixcheck(B):
optsgiven := {seq(args[i], i=3..nargs)}:
optioncheck(optsgiven,{`list`,`matrix`,`red`}):
A := listlistmatrix2matrix(A):
B := listlistmatrix2matrix(B):
C := evalm(linalg[concat](A,-B)):
L := intkernel(C,matrix);
L := linalg[delrows](L,linalg[coldim](A)+1..linalg[rowdim](L)):
L := latticebasis(L):
if evalb(`red` in optsgiven) then
  L := listlistmatrix2listlist(L):      
  L := lattice(L,integer):
end if:
listlistmatrixoutput(L,optsgiven):
end proc;

intprojection := proc(L,opt)
local B, optsgiven, n, r, U:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
optsgiven := {seq(args[i], i=2..nargs)}:
optioncheck(optsgiven, {`red`,`list`,`matrix`}):
B := listlistmatrix2matrix(B):
n:=linalg[rowdim](B):
r := linalg[rank](B):
if r = 0 then
  U := linalg[diag](1$n):
elif r = n then
  U := matrix([[0$n]]):
else
  U := ihermiterowops(B)[2]:
  U := linalg[delrows](U,1..r):
    if evalb(`red` in optsgiven) then
    U := convert(U,listlist):   
    U := lattice(U,integer):
    U := convert(U,matrix):
  end if:
end if:
listlistmatrixoutput(U,optsgiven):
end proc;

intsection := proc()
local B, optsgiven, U, m, n:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
optsgiven := {seq(args[i], i=2..nargs)}:
optioncheck(optsgiven, {`list`,`matrix`}):
B := listlistmatrix2matrix(B):
m := linalg[rowdim](B):
n := linalg[coldim](B):
if m = n then 
  U := linalg[inverse](B):
else
  U := ihermitecolops(B)[2]:
  U := linalg[delcols](U,m+1..n):
end if:
listlistmatrixoutput(U,optsgiven):
end proc:

isprimitive := proc() 
local B, n, j:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
B := listlistmatrix2matrix(B):
B := linalg[ismith](B):
n := linalg[rank](B):
if n=0 then 
  return true:
end if: 
if B[n,n]>1 then
  return false:
end if: 
true:
end proc;

issurjective := proc() 
local B, n, j:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
B := listlistmatrix2matrix(B):
if linalg[rank](B) < linalg[rowdim](B) then 
  return false:
end if: 
if isprimitive(B) then
  return true:
end if: 
false:
end proc;

latticebasis := proc()
local B, optsgiven, n, r, H:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
optsgiven := {seq(args[i], i=2..nargs)}:
optioncheck(optsgiven, {`red`,`list`,`matrix`}):
B := listlistmatrix2matrix(B):
n:=linalg[coldim](B):
r := linalg[rank](B):
if r = 0 then
  H := [[0$linalg[rowdim](B)]]:
else
  H := ihermitecolops(B)[1]:
  if n > r then 
    H := linalg[delcols](H,r+1..n):
  end if:
  H := listlistmatrix2listlist(H):
  if evalb(`red` in optsgiven) then   
    H := lattice(H,integer):
  end if:
end if:
listlistmatrixoutput(H,optsgiven):
end proc:

matrix2cols := proc(A::matrix)
listlistmatrix2listlist(A):
end proc:

primitivespan := proc()
local B, optsgiven, n, m, r, U, V, PB:
B := args[1]:
listlistmatrixcheck(B):
integerentriescheck(B):
optsgiven := {seq(args[i], i=2..nargs)}:
optioncheck(optsgiven, {`red`,`list`,`matrix`}):
B := listlistmatrix2matrix(B):
n := linalg[coldim](B):
m := linalg[rowdim](B):
r := linalg[rank](B):
if r = 0 then
  PB := [[0$m]]:
else
  linalg[ismith](B,`U`,`V`):
  PB := linalg[inverse](U):
  if r < m then
    PB := linalg[delcols](PB,r+1..m):
    end if:
  PB := listlistmatrix2listlist(PB):
  if evalb(`red` in optsgiven) then   
    PB := lattice(PB,integer):
  end if:
end if:
listlistmatrixoutput(PB,optsgiven):
end proc:

#
# Definition of procedures on polyhedra
#

bunch := proc(Q::matrix,CL::list)
if nargs = 2 then
  bunchcheck(Q,CL):
end if:
if nargs > 2 and args[3] <> `nocheck` then
  error "wrong number/type of arguments"  
end if:
BUNCH(`BUNCH`,Q,CL,linalg[coldim](Q),linalg[rowdim](Q),nops(CL)):
end proc;

bunchcones := proc(B::BUNCH)
op(3,B):
end proc;

bunchprojection := proc(B::BUNCH)
evalm(op(2,B)):
end proc;

bunch2fan := proc(B::BUNCH, Li)
local Q, CB, DCB, P, PDCB, F:
if nargs > 1 and type(Li,list) then
  Q := evalm(Li[2]):
  P := evalm(Li[1]):
else 
  Q := bunchprojection(B):
  P := linalg[transpose](intkernel(Q,red,matrix)):
end if:
CB := covcoll(B):
DCB := dualface(posorthant(linalg[coldim](Q)),CB)[2]:
PDCB := projectcones(DCB,P):
F := fan(op(PDCB)):
if nargs > 1 and not type(args[2],list) then 
  `Li` := [evalm(P), evalm(Q)]:
end if:
F:
end proc;

cocoref := proc(Li::{listlist,matrix}, sigma)
local n, L, added, CL, cl, CLa, cla, CLn, CLgf, i, j, CLij, behalt, m, IL:
L := listlistmatrix2listlist(Li):
m := nops(L):
n := nops(L[1]):
IL := combinat[choose](m,n):
cl := nops(IL):
CL := [seq(poshull(seq(L[IL[i][k]],k=1..n)),i=1..cl)]:
CLa := []:
for i to cl do
  if dim(CL[i]) = n then
    CLa := [op(CLa),CL[i]]:  
  end if:
end do:
CLgf := []:
added := true:
CLa := mincones(CLa):
while added do
  added := false:
  cla := nops(CLa):
  CLn := []:
  for i to cla do
    behalt := 0:
      for j to cl do
      CLij := intersection(CL[j],CLa[i]):
      if dim(CLij) = n then
        if contains(CL[j], CLa[i]) then
          behalt := behalt + 1:
        else
          added := true:      
          CLn := [CLij,op(CLn)]:
        end if:
      else
        behalt := behalt + 1:
      end if:
    end do:
    if behalt = cl then
       CLgf := [op(CLgf), CLa[i]]:
    end if:
  end do:
  CLn := reduc(CLn):
  CLa := CLn:
end do:
fan(op(CLgf)):
end proc:

imagefan := proc(sigma, Qi::{listlist,matrix})
local L, m, n, IL, added, CL, cl, CLa, cla, CLn, CLgf, i, j, CLij, behalt, Q, Qm:
Q := listlistmatrix2listlist(Qi):
Qm := cols2matrix(Q):
m := nops(Q):
n := nops(Q[1]):
if type(sigma, CONE) then
  IL := faces(sigma)[n]:
elif type(sigma, FAN) then
  IL := maximal(skeleton(sigma, n)):  
else
  error("first argument must be a cone or a fan"):
end if:
cl := nops(IL):
CL := map(tau->image(convert(tau,CONE),Qm), IL):
CL := select(c -> dim(c) = n, CL):
refinecones(CL):
end proc:

covcoll := proc(B::BUNCH)
local Q, q, BCL, d, indset, IL, CCIL, i, BCind, BCrem, j, C,
found, k:
Q := listlistmatrix2listlist(bunchprojection(B)):
q := nops(Q):
BCL := bunchcones(B):
d := min(op(map(dim,BCL))):
indset := {seq(i,i=1..q)}:
IL := {}:
for i from d to q do
  IL := [op(IL),op(combinat[choose](q,i))]:
end do:
CCIL := []:
while IL <> [] do
IL := nopssort(IL,q):
  C := poshull(seq(Q[IL[1][j]],j=1..nops(IL[1]))):
  found := false:
  for j to nops(BCL) while not found do
    k := j:
    if relintcontains(C,BCL[j]) then
      found := true:   
    end if:
  end do:
  if found then 
    CCIL := [op(CCIL),IL[1]]:
    IL := [op({op(IL)} minus groessere(IL[1],indset))]:
  else
    IL := [op({op(IL)} minus {IL[1]})]:
  end if:
end do:
map2(posorthantface,q,CCIL):
end proc:

dualface := proc(C::CONE,F::{CONE,list})
local DC, dualface1, i:
DC := dual(C):
dualface1 := proc(DC1,F1)
intersection(DC1,dual(linearhull(F1))):
end proc:
if type(F,CONE) then
  if not isface(F,C) then
    error "second cone must be a face of the first one"
  end if:
  return ([DC,dualface1(DC,F)]):
else
  for i to nops(F) do
    if not type (F[i],CONE) and isface (F[i],C) then 
       error "second argument must be a list of faces of the first argument" 
    end if:
  end do:
  return [DC,map2(dualface1,DC,F)]:
end if:
end proc;

fan2bunch := proc(F::FAN, Li)
local P, Q, p, MC, DMC, QDMC, B:
if nargs > 1 and type(Li,list) then
  P := listlistmatrix2listlist(Li[1]):
  Q := evalm(Li[2]):
else
  P := convert(rays(F),list):
  Q := linalg[transpose](intkernel(P,red,matrix)):
end if:
if not evalb(`nocheck` in {args}) then
  if linalg[rank](listlistmatrix2matrix(P)) < ambientdim(F) 
  or not issurjective(P) then
    error "primitive generators of fan should generate the lattice":
  end if: 
end if:
p := nops(P):
MC := map(liftcone,maximal(F),p,P):
DMC := dualface(posorthant(p),MC)[2]:
QDMC := map(image,DMC,Q):
QDMC := mincones(QDMC):
if not evalb(`nocheck` in {args}) then 
  if not isbunchmaximal(Q,QDMC) then
    error "expecting a 2-complete fan"
  end if:
end if:
B := bunch(Q,QDMC,nocheck):
if nargs > 1 and not type(Li,list) and not evalb(Li=`nocheck`) then
  `Li` := [evalm(listlistmatrix2matrix(P)),evalm(Q)]:
end if:
B:
end proc:

freecovering := proc(F::FAN)
local MC,RF,RM,i,NMC,NMCR;
MC := maximal(F):
RF := [op(rays(F))]:
RM := latticebasis(RF,matrix):
RM:=linalg[inverse](RM):
NMC:=[]:
for i from 1 to nops(MC) do
   NMCR := map(proc(x) evalm(RM &* x): end, rays(MC[i])):
   NMC := [op(NMC), poshull(op(NMCR))]:
end do:
fan(op(NMC)):
end:
  
intersectrelint := proc(C1::CONE,C2::CONE)
local DC1, DC2, DCF, OCF:
DC1 := dual(C1):
DC2 := dual(C2):
DCF := intersection(negat(DC1),DC2):
OCF := intersection(lineality(DC1),lineality(DC2)):
contains(OCF,DCF):
end proc;

isprojectedface := proc(C::CONE,Q::matrix)
local indiceslist, j, testkegel:
indiceslist := combinat[choose]([seq(i,i=1..linalg[coldim](Q))]):
if ambientdim(C) <> linalg[rowdim](Q) then
  return false:
end if:
for j to nops(indiceslist) do
  testkegel := weightcone(indiceslist[j],Q):
  if contains(testkegel,C) and contains(C,testkegel) then
    return true:
  end if:
end do:
false:
end proc;

isstandard := proc(B::BUNCH)
local coxy,cont,testcone,DM,DL,BM,BL,nbl,i,j:
if nargs > 1 and args[2]<>`bunchcheck` then
  error "wrong number/type of arguments"  
end if:
BM := bunchprojection(B):
BL := bunchcones(B):
if nargs = 2 then 
  bunchcheck(BM,BL):
end if:
nbl := nops(BL):
coxy := true:
for i from 1 to linalg[coldim](BM) while coxy do    
  DM := linalg[delcols](BM,i..i):
  if not(issurjective(DM)) then 
    coxy := false:
  end if:
  cont := false:
  testcone := poshull(seq(linalg[col](DM,j),j=1..linalg[coldim](DM))):
  for j from 1 to nbl while coxy and not(cont) do
    cont := contains(testcone,BL[j]) and intersectrelint(BL[j],testcone):
  end do:
  coxy:=cont:
end do:
end proc;
 
pairwiseintersectrelint := proc(CL::list)
local i,j:
coneslistcheck(CL,commonambientspace):
for i to nops(CL)-1 do
  for j from i+1 to nops(CL) do
    if not intersectrelint(CL[i],CL[j]) then 
      return false 
    end if:
  end do:
end do:
true:
end proc;

relintcontains := proc(C1::CONE,C2::CONE)
evalb(contains(C1,C2) and intersectrelint(C1,C2)):
end proc:

relintiscontained := proc(C1::CONE,C2::CONE)
evalb(iscontained(C1,C2) and intersectrelint(C1,C2)):
end proc:

#
# Definition of procedures on toric varieties
#

amplecone := proc(F::{FAN,BUNCH})
local B, BC, AC, i:
if type(F,FAN) then
  B := fan2bunch(args):
else
  B := F:
end if:
BC := bunchcones(B):
AC := BC[1]:
for i from 2 to nops(BC) do
  if intersectrelint(AC,BC[i]) then
    AC := intersection(AC,BC[i]) 
  else
    error "ample cone is empty"
  end if:
end do:
AC:
end proc:

canonclass := proc(F::{FAN,BUNCH})
local B, Q, u:
if type(F,FAN) then
  B := fan2bunch(args):
else 
  B := F:
end if:
Q := bunchprojection(B):
u := [-1$linalg[coldim](Q)]:
evalm(Q &* u):
end proc;

cartierdiv := proc(F::{FAN,BUNCH})
local CF, CC, Q, RCC, i, L, Pic:
if type(F,FAN) then 
  CF := coxconstr(F):
  CC := dualface(posorthant(nops(rays(F))),CF[2])[2]:
  if nargs > 2 and type (args[2],list) then
    Q := evalm(args[2][2]):
  else
    Q := linalg[transpose](intkernel(CF[1],red,matrix)):
  end if:
else
  CC := covcoll(F):
  Q := bunchprojection(F):
end if:
L := []:
RCC := map(rays,CC):
for i from 1 to nops(RCC) do
  L := [op(L),intimage(Q,RCC[i])]:  
end do:
Pic := L[1]:
for i from 2 to nops(L) do
  Pic := intersectlattices(Pic, L[i]):
end do:
Pic := listlistmatrix2listlist(Pic):
intpreimage(Q,Pic,red):
end proc:

coxconstr := proc(F::FAN)
local P, MC:
if nargs > 2 and type(args[2],list) then
  P := listlistmatrix2listlist(args[2][1]):
else
  P := convert(rays(F),list):
end if:
MC := map(liftcone,maximal(F),nops(P),P):
if `fan` in {args} then
  [listlistmatrix2matrix(P),fan(op(MC))]:
else
  [listlistmatrix2matrix(P),convert(MC,list)]:
end if:
end proc:
  
effectivecone := proc(Bi::{FAN,BUNCH})
local B, Q:
if type(Bi,FAN) then 
  B := fan2bunch(args)
else
  B := Bi:
end if:
Q := bunchprojection(B):
poshull(op(listlistmatrix2listlist(Q))):
end proc;

isdivisorial := proc(F::FAN)
local CF, CFP,CFC, CFPt, KFP, Q, Cdiv, Cdivt, KFC, divi, delta, i:
CF := coxconstr(F):
CFP := CF[1]:
CFC := CF[2]:
Q := intkernel(CFP,red,matrix):
Cdiv := cartierdiv(F, [Q,CFP]):
Cdiv := listlistmatrix2matrix(Cdiv):
Cdivt := linalg[transpose](Cdiv):
CFPt := linalg[transpose](CFP):
KFP := linalg[transpose](linalg[linsolve](Cdiv,CFPt)):
delta := projectcones(posorthant(ambientdim(CFC[1])),Cdivt):
KFC := projectcones(CFC, Cdivt):
divi := true:
for i from 1 to nops(KFC) while divi do
  divi:=isface(KFC[i],delta):
end do:
divi:
end proc:

isfano := proc(Bi::{BUNCH,FAN})
local B, c, L, CA:
if type(Bi,FAN) then
  B := fan2bunch(Bi):
else 
  B := Bi:
end if:
c := convert(evalm(-1*canonclass(B)),list):
L := picardgroup(B):
CA := amplecone(B):
evalb(intcontains(L,c) and relintcontains(CA,poshull(c))):
end proc:

isgorenstein := proc(Bi::{BUNCH,FAN})
local B, c, L:
if type(Bi,FAN) then
  B := fan2bunch(Bi):
else 
  B := Bi:
end if:
c := convert(evalm(-1*canonclass(B)),list):
L := picardgroup(B):
intcontains(L,c):
end proc:

isprojective := proc(F::FAN)
evalb(iscomplete(F) and isquasiprojective(F)):
end proc:

isquasiprojective := proc(F::FAN)
local CF, n, tau, i, CC, d, A, DM, PM:
CF := coxconstr(F):
A := CF[1]:
d := linalg[coldim](A):
CC := CF[2]:
DM := dualface(posorthant(d),CC)[2]:
A := linalg[kernel](A):
A := matrix([op(A)]):
PM := projectcones(DM,A):
PM := mincones(PM):
n := nops(PM):
tau:=PM[1]:
for i from 2 to n do
  if intersectrelint(tau,PM[i]) then
    tau := intersection(tau,PM[i]) 
  else
    return false 
  end if:
end do:
true:
end proc;


istwocomplete := proc(F::FAN)
local B, FF, MCF, MCFF, SMCF, SMCFF, PQ;
B := fan2bunch(F,PQ,nocheck):
if not isbunchmaximal(bunchprojection(B),bunchcones(B)) then
  return false:
end if:
FF := bunch2fan(B,PQ):
MCF := map(rays,maximal(F)):
MCFF := map(rays,maximal(FF)):
SMCF := {seq(convert(MCF[i],set),i=1..nops(MCF))};
SMCFF := {seq(convert(MCFF[i],set),i=1..nops(MCFF))};
evalb(SMCF=SMCFF):
end proc;

kajiwaraconstr := proc(F::FAN)
local CF, CFP,CFC, CFPt, KFP, Q, Cdiv, Cdivt, KFC, divi, delta, i, optarg, out:
if nargs > 1 then
  optarg := args[2]
end if:
optionscheck(optarg,`fan`):
CF := coxconstr(F):
CFP := CF[1]:
CFC := CF[2]:
Q := intkernel(CFP,red,matrix):
Cdiv := cartierdiv(F, [Q,CFP]):
Cdiv := listlistmatrix2matrix(Cdiv):
Cdivt := linalg[transpose](Cdiv):
CFPt := linalg[transpose](CFP):
KFP := linalg[transpose](linalg[linsolve](Cdiv,CFPt)):
delta := projectcones(posorthant(ambientdim(CFC[1])),Cdivt):
KFC := projectcones(CFC, Cdivt):
divi := true:
for i from 1 to nops(KFC) while divi do
  divi:=isface(KFC[i],delta):
end do:
if not(divi) then
  error "Fan is not divisorial"
end if:
if evalb(optarg=`fan`) then
  out := fan(op(KFC)):
else 
  out := KFC:
end if:  
[evalm(KFP),delta,out]:
end proc:

movingcone := proc(B::{FAN,BUNCH})
local tau, i, A, L, H, S:
if type(B,FAN) then
  S := fan2bunch(args): 
else
  S := B
end if:
A := bunchprojection(S):
L := [linalg[col](A,1..linalg[coldim](A))]:
tau := []:
for i from 1 to linalg[coldim](A) do
H := L:
H := subsop(i=NULL,H):
tau := [op(tau),poshull(op(H))]:
end do:
H := tau[1]:
for i from 2 to linalg[coldim](A) do
H := intersection(H,tau[i]):
end do:
H:
end proc;

picardgroup := proc(F::{FAN,BUNCH})
local CF, CFL, CFP, CC, RCC, i, L, A, Pic:
if type(F,FAN) then 
  CF := coxconstr(F):
  CFL := CF[2]:
  CC := dualface(posorthant(nops(rays(F))),CFL)[2]:
  if nargs > 2 then
    CFP := evalm(args[2][1]):
    A := evalm(args[2][2]):
  else
    CFP := CF[1]:
    A := linalg[transpose](intkernel(CF[1],red,matrix))
  end if:
else
  CC := covcoll(F):
  A := bunchprojection(F):
end if:
L := []:
RCC := map(rays,CC):
for i from 1 to nops(RCC) do
  L := [op(L),intimage(A,RCC[i])]:
end do:
Pic := L[1]:
for i from 2 to nops(L) do
  Pic := intersectlattices(Pic, L[i]):
end do:
listlistmatrix2listlist(Pic):
end proc;

samplecone := proc(F::{FAN,BUNCH})
local B, SAC, BC, i:
if type(F,FAN) then 
  B := fan2bunch(args)
else
  B := F
end if:
BC := bunchcones(B):
SAC := BC[1]:
for i from 2 to nops(BC) do
SAC := intersection(SAC,BC[i])
end do:
SAC:
end proc;

twocompletion := proc(F::FAN)
local NB,B,BC,PQ,Q:
B := fan2bunch(F,PQ,nocheck):
BC := bunchcones(B): 
Q := PQ[2]:
NB := bunching(Q,BC):
bunch2fan(NB,PQ):
end proc;

#
# Definition of functions on GIT
#

chamber := proc(w::list,Li::{listlist,matrix})
local L, m, n, IL, CL, cl, CLa, i;
L := listlistmatrix2listlist(Li):
L := convert(convert(L,set),list):
m := nops(L):
n := nops(L[1]):
IL := combinat[choose](m,n):
cl := nops(IL):
CL := [seq(poshull(seq(L[IL[i][k]],k=1..n)),i=1..cl)]:
CLa := poshull(op(L)):
for i to cl do
  if dim(CL[i]) = n and iscontained(poshull(w),CL[i]) then
    CLa := intersection(CLa, CL[i]):  
  end if:
end do:
CLa:
end proc:

gitfan := proc(L::{listlist,matrix})
cocoref(L):
end proc:

gitlimit := proc(L::{listlist,matrix, list(matrix)}, sigma)
local P:
if type(L,list(matrix)) then
  P := L[1]:
else
  P := linalg[transpose](intkernel(L, matrix, red)): 
fi:
if nargs = 2 then
  imagefan(sigma, P):
else
  cocoref(P):
end if:
end proc:

admitsgoodquot := proc(F::FAN, Q::{listlist,matrix})
local d, MF, DFM, PDFM:
MF := maximal(F):
d := ambientdim(F):
DFM := dualface(posorthant(d), MF)[2]:
PDFM := projectcones(DFM, Q):
pairwiseintersectrelint(PDFM):
end proc:

quotientfan := proc(F::FAN, Li::{listlist, matrix, list(matrix)})
local PF, P, Q, MF, PP, gers, check:
if type(Li,list(matrix)) then
  P := Li[1]:
  Q := Li[2]:
else
  Q := listlistmatrix2listlist(Li):
  P := linalg[transpose](intkernel(Q, matrix)): 
fi:
if nargs > 2 then 
  check := args[3]:
end if:
if not evalb(check = `nocheck`) then 
  if not(admitsgoodquot(F,Q)) then 
    error "fan admits no quotient"
  end if:
end if:  
MF := maximal(F):
PF := projectcones(MF,P):
gers := lines(PF[1]):
if nops(gers) = 0 then
  return fan(op(PF)):
elif linalg[rank](listlistmatrix2matrix(gers)) = linalg[rowdim](P) then
  return fan(zerocone(0)):
end if:
PP := completeseq([op(lines(PF[1]))], inj)[2]:
fan(op(projectcones(PF,PP))):
end proc:

semistablepoints := proc(w::list, Li::{listlist,matrix, list(matrix)})
local L, m, n, IL, CL, cl, BIL, i;
if type(Li,list(matrix)) then
  L := listlistmatrix2listlist(Li[2]):
else
  L := listlistmatrix2listlist(Li):
fi:
m := nops(L):
n := nops(L[1]):
IL := []:
for i to n do 
  IL := [op(IL), op(combinat[choose](m,i))]:
end do:
cl := nops(IL):
CL := [seq(poshull(seq(L[IL[i][k]],k=1..nops(IL[i]))),i=1..cl)]:
BIL := []:
for i to cl do
  if relintiscontained(poshull(w),CL[i]) then
    BIL := [op(BIL), IL[i]]:  
  end if:
end do:
BIL := map2(posorthantface,m,BIL):
BIL := dualface(posorthant(m),BIL)[2]:
if BIL = [] then
  fan(zerocone(m)):
else
  fan(op(BIL)):
end if:
end proc:

weight2bunch := proc(w::list,Li::{listlist,matrix})
local L, m, n, IL, CL, cl, BCL, i;
L := listlistmatrix2listlist(Li):
m := nops(L):
n := nops(L[1]):
IL := []:
for i to n do 
  IL := [op(IL), op(combinat[choose](m,i))]:
end do:
cl := nops(IL):
CL := [seq(poshull(seq(L[IL[i][k]],k=1..nops(IL[i]))),i=1..cl)]:
BCL := []:
for i to cl do
  if relintiscontained(poshull(w),CL[i]) then
    BCL := [op(BCL), CL[i]]:  
  end if:
end do:
BCL := mincones(BCL):
bunch(listlistmatrix2matrix(L),BCL,nocheck):
end proc:

ppdivisor := proc(Q::{listlist,matrix,list(matrix)})
local delta, origin, tail, Mseq, Nseq, r, F, RF, i, rri, rridelta, Delta, ppcoeff;
if type(args[1],list(matrix)) then
   Mseq := [linalg[transpose](args[1][1]),args[1][2]];
   Nseq := [linalg[transpose](args[1][2]),args[1][1]];
   if nops(args[1]) = 3 then
      r := args[1][3]
   else
      r := intsection(Mseq[2],matrix);
   fi:
else
   Mseq := completeseq(Q,surj);
   Nseq := dualseq(Mseq);
   r := intsection(Mseq[2],matrix);
fi:
r := linalg[transpose](r);
F := gitlimit([Nseq[2],Mseq[2]]);
RF := rays(F);
delta := posorthant(linalg[coldim](Mseq[2]));
origin := vector(ambientdim(F), 0);
rri := preimage(convhull(origin), Nseq[2]);
tail := recession(image(intersection(rri, convert(delta, affine)), r));
ppcoeff := [];
for i from 1 to nops(RF) do
   rri := preimage(convhull(RF[i]),Nseq[2]);
   rridelta := intersection(rri, convert(delta,affine));
   Delta := image(rridelta,r);
   ppcoeff := [op(ppcoeff),[RF[i], Delta]];   
od;
[F, poldiv(F,ppcoeff, tail)];
end;

ppfan := proc(sigma, Q::{listlist,matrix,list(matrix)})
local delta, origin, Mseq, Nseq, r, F, RF, i, rri, rridelta, Delta, ppcoeff, ppfan, max, rr, ker, tail:
if type(Q,list(matrix)) then
   Mseq := [linalg[transpose](Q[1]),Q[2]];
   Nseq := [linalg[transpose](Q[2]),Q[1]];
   if nops(Q) = 3 then
      r := Q[3]
   else
      r := intsection(Mseq[2],matrix);
   fi:
else
   Mseq := completeseq(Q,surj);
   Nseq := dualseq(Mseq);
   r := intsection(Mseq[2],matrix);
fi:
r := linalg[transpose](r):
F := gitlimit([Nseq[2], Mseq[2]], sigma):
RF := [op(rays(F))]:
origin := vector(ambientdim(F), 0):
ppfan := []:
rr := map(R -> preimage(convhull(R), Nseq[2]), RF):
ker := preimage(convhull(origin), Nseq[2]):
if type(sigma, CONE) then
  max := [sigma]:
else
  max := maximal(sigma):
end if:
max := map(delta -> convert(delta, affine), max):
for delta in max do
   tail := recession(image(intersection(ker, delta), r)):
   ppcoeff := []:
   for i to nops(RF) do
      Delta := image(intersection(rr[i], delta), r):
      ppcoeff := [op(ppcoeff), [RF[i], Delta]]:
   end do:
   ppfan := [op(ppfan), poldiv(F,ppcoeff, tail)]:
end do:
[F, ppfan]:
end proc:


##
## polyhedral divisor data type
##

# POLDIV(base :: FAN, basedim :: integer, tail :: CONE, torusdim :: integer,
#             coeffs :: [[ray,POLYHEDRON]])
#
# base           fan of the base toric variety Y
# basedim     dimension of the base variety
# tail             tail cone sigma of the polyhedral divisor
# torusdim    dimension of the torus acting on X = rank of the lattice containing sigma
# coeffs        list associating to each toric prim divisor on Y, i.e., each ray of the fan of
#                   Y, its polyhedral coefficient; each of these has tail cone equal to 'tail'
#  
# basedim = ambientdim(base), torusdim = ambientdim(tail) are redundant
#   (needed for print/POLDIV, though)

# construct polyhedral divisor; tail is optional
poldiv := proc(base :: FAN, coeffs :: list, t)
local tail:
if nargs = 2 then
  # we could loop until we find a non-empty coefficient to be more forgiving 
  tail := recession(coeffs[1][2]):
else
  tail := t:
end if:
POLDIV(base,ambientdim(base),tail,ambientdim(tail),coeffs):
end proc:

# used for creating the data type, see setup()
poldiv_type := proc(P)
  evalb(op(0,P) = `POLDIV`):
end proc:

poldiv_print := proc(base, basedim, tail, torusdim, coeffs)
  `POLDIV`(basedim,torusdim)
end proc:  

# extract data
base := proc(P :: POLDIV)
  op(1,P):
end proc:

basedim := proc(P :: POLDIV)
  op(2,P):
end proc:

tailcone := proc(P :: POLDIV)
  op(3,P):
end proc:

torusdim := proc(P :: POLDIV)
  op(4,P):
end proc:

coefficients := proc(P :: POLDIV)
  op(5,P):
end proc:

# compute slices of divisorial fans
# weights is a list of pairs [ray,weight] or a function ray -> weight
slice := proc(divfan :: list, weights)
  local result, origin, ray, weight, imat, n, wmat, i, j, coeff, rs, ws:
  rs := rays(base(divfan[1])):
  ws := [seq(0,i=1..nops(rs))]:
  if type(weights, procedure) then
    for i to nops(rs) do
       ws[i] := weights(rs[i]):
    end do:
  end if:
  if type(weights, list) then
    for i to nops(rs) do
       ws[i] = lookup(rs[i], weights, 0):
    end do:
  end if:
  n := torusdim(divfan[1]):
  imat := array(1..n,1..n,identity):
  origin := convhull(vector(torusdim(divfan[1]), 0)):
  result := map(x -> origin, divfan):
  for i to nops(rs) do
     ray := rs[i]:
     weight := ws[i]:
     if weight = 0 then next: end if:
     wmat := linalg[scalarmul](imat, weight):
     for j to nops(divfan) do
        coeff := lookup(ray, coefficients(divfan[j])):
        coeff := image(coeff, wmat):
        result[j] := minkowskisum(result[j], coeff):
     end do:
  end do:
  result:
end proc:

#
# Definition of examples
#

cutpyramid := proc()
local v1,v2,v3,v4,v5,v6,C1,C2,C3,C4,C5,C6,C7,C8:
v1 := vector([-1,0,0]):
v2 := vector([0,-1,0]):
v3 := vector([0,0,-1]):
v4 := vector([0,1,1]):
v5 := vector([1,0,1]):
v6 := vector([1,1,0]):
C1 := poshull(v1,v4,v6):
C2 := poshull(v1,v3,v6):
C3 := poshull(v3,v5,v6):
C4 := poshull(v2,v3,v5):
C5 := poshull(v2,v4,v5):
C6 := poshull(v1,v2,v4):
C7 := poshull(v1,v2,v3):
C8 := poshull(v4,v5,v6):
fan(C1,C2,C3,C4,C5,C6,C7,C8):
end proc;

freebentcube := proc()
local v1,v2,v3,v4,v5,v6,v7,v8,C1,C2,C3,C4,C5,C6;
v1 := vector([1,1,-1]):
v2 := vector([-1,1,0]):
v3 := vector([-1,-1,0]):
v4 := vector([1,-1,-1]):
v5 := vector([1,2,1]):
v6 := vector([-1,1,1]):
v7 := vector([-1,-1,1]):
v8 := vector([1,-1,0]):
C1 := poshull(v1,v2,v3,v4):
C2 := poshull(v1,v2,v5,v6):
C3 := poshull(v2,v3,v6,v7):
C4 := poshull(v3,v4,v7,v8):
C5 := poshull(v4,v1,v8,v5):
C6 := poshull(v5,v6,v7,v8):
fan(C1,C2,C3,C4,C5,C6):
end proc;

hirzebruch := proc(a::integer)
local v, C:
v := array(1..4):
C := array(1..4):
v[1] := [1,0]:
v[2] := [0,1]:
v[3] := [-1,a]:
v[4] := [0,-1]:
C[1] := poshull(v[1],v[2]):
C[2] := poshull(v[2],v[3]):
C[3] := poshull(v[3],v[4]):
C[4] := poshull(v[1],v[4]):
fan(C[1],C[2],C[3],C[4]):
end proc;


setup();

end module:

savelibname:="/home/fenn/vollmert";

savelib( `TorDiv13` );
