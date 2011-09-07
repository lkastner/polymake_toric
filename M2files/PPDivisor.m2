---------------------------------------------------------------------------
-- PURPOSE: Computations with polyhedral divisors
-- PROGRAMMER : Ren??Birkner 
-- UPDATE HISTORY : March 2009
---------------------------------------------------------------------------
newPackage("PPDivisor",
    Headline => "A package for computations with polyhedral divisors",
    Version => "0.2",
    Date => "April 22, 2009",
    Authors => {
         {Name => "Ren??Birkner",
	  HomePage => "http://page.mi.fu-berlin.de/rbirkner/index.htm",
	  Email => "rbirkner@mi.fu-berlin.de"}},
    DebuggingMode => true,
    Configuration => {}
    )

export {gitFanStructure, delta, PolyhedralDivisor, makePolDiv, base, basedim, completeSequence, integerSection, ppcoefficients, torusdim, ppFan}

needsPackage "Polyhedra"

-- Defining the new type Polyhedron
PolyhedralDivisor = new Type of MutableHashTable
PolyhedralDivisor.synonym = "proper polyhedral divisor"
PolyhedralDivisor.GlobalAssignHook = globalAssignFunction
PolyhedralDivisor.GlobalReleaseHook = globalReleaseFunction


-- Modifying the standard output for a polyhedron to give an overview of its characteristica
net PolyhedralDivisor := PD -> ( info := hashTable{"base dimension" => PD#"fanDimension",
						   "torus dimension" => PD#"torusDimension",
						   "number of rays" => #(PD#"polyhedralCoefficients")};
				 horizontalJoin flatten (
				      "{", 
				      -- the first line prints the parts vertically, second: horizontally
				      stack (horizontalJoin \ sort apply(pairs info,(k,v) -> (net k, " => ", net v))),
				      -- between(", ", apply(pairs x,(k,v) -> net k | "=>" | net v)),
				      "}" ))
			    
			    
makePolDiv = method(TypicalValue => PolyhedralDivisor)
makePolDiv(Fan,List,Cone) := (F,ppcoeff,tailC) -> (
     PD := new PolyhedralDivisor;
     PD#"fan" = F;
     PD#"fanDimension" = ambDim(F);
     PD#"tailCone" = tailC;
     PD#"torusDimension" = ambDim(tailC);
     PD#"polyhedralCoefficients" = ppcoeff;
     PD)


base = method(TypicalValue => Fan)
base PolyhedralDivisor := PD -> (
     PD#"fan");


basedim = method(TypicalValue => ZZ)
basedim PolyhedralDivisor := PD -> (
     PD#"fanDimension");


tailCone PolyhedralDivisor := PD -> (
     PD#"tailCone");


torusdim = method(TypicalValue => ZZ)
torusdim PolyhedralDivisor := PD -> (
     PD#"torusDimension");


ppcoefficients = method()
ppcoefficients(PolyhedralDivisor) := PD -> (
     L := PD#"polyhedralCoefficients";
     hashTable apply(L, l -> ( l#0 => l#1)));


completeSequence = method()
completeSequence (Matrix,String) := (M,sp) -> (
     if (sp == "inj") then (
	  (M,transpose(gens(ker(transpose(M))))))
     else if (sp == "surj") then (
	  (gens(ker(M)),M))
     else (
	  error ("option must be either 'surj' or 'inj'")));


integerSection = method()
integerSection Matrix := M -> (
     m := numRows(M);
     (transpose((smithNormalForm(M))#2))^{0..(m-1)})


ppFan = method()
ppFan (Cone,Matrix,Matrix,Matrix) := (C,M,N,r) -> (
     -- todo: documentation
     MSeq := {transpose(M),N};
     NSeq := {transpose(N),M};
     r = transpose r;
     print("computing imagefan");
     F := imageFan(M,C);
     print("done");
     RF := rays(F);
     n := ambDim(F);
     origin := map(QQ^n,QQ^1,0);
     print("computing preimages");
     preimrays := apply(RF, r -> ( affinePreimage(M,convexHull(r))));
     preimorigin := affinePreimage(M,convexHull(origin));
     print("done");
     local maxCones;
     if instance(C,Cone) then (
	  maxCones = {C})
     else (
	  maxCones = maxCones(C));
     --<< #maxCones << endl;
     newppfan := apply(maxCones, Cm -> (
	       tailCm := tailCone(affineImage(r,intersection(preimorigin,coneToPolyhedron(Cm))));
	       -- Getting polyhedral coefficient for each ray:
	       ppcoeff := apply(#RF, i -> (
   			 Delta := affineImage(r,intersection(preimrays#i,coneToPolyhedron(Cm)));
	   		 {RF#i,Delta}));
	       print("done");
	       PD := makePolDiv(F,ppcoeff,tailCm);
	       PD));
     (F,newppfan));

delta = method()
delta(Cone, Matrix, Matrix, Matrix) := (C,t,p,a) -> (
     -- Sequence: 0 -> N <-t- \tilde{N} -p-> N_Y -> 0
     -- a\in N_Y
     -- C\subseteq \tilde{N} a cone
     -- returns delta(a)\subseteq N
     -- todo: describe what delta(a) means
     affineImage(t, intersection(affinePreimage(p,convexHull(a)),coneToPolyhedron(C)))
     )

gitFanStructure = method()
gitFanStructure(Cone, Matrix) := (CDual, DEG) -> (
     C := dualCone CDual;
     MSeq := completeSequence(DEG,"surj");
     iM := MSeq#0;
     pM := MSeq#1;
     pN := transpose iM;
     iN := transpose pM;
     tN := integerSection(MSeq#1);
     sM := transpose tN;
     m := inverse(pN||tN);
     sN := submatrix(m,,{0..(numgens target pN)-1});
     tM := transpose sN;
     << "Computing GIT fan." << endl;
     gitFan := imageFan(transpose iN, CDual);
     pFan := ppFan(C, pN, transpose iN, transpose tN);
     Sigma := pFan#0;
     gensSigma := maxCones Sigma;
     -- The following three lines assign indices to rays and cones of Sigma and the GIT fan.
     SigmaRayHash := hashTable(toList apply(#(rays Sigma), i-> {(rays Sigma)#i, "sr" | (toString i)}));
     gitFanRayHash := hashTable(toList apply(#(rays gitFan), i-> {(rays gitFan)#i, "gr" | (toString i)}));
     SigmaConeHash := hashTable(toList apply(#gensSigma, i->{gensSigma#i, "sc" | (toString i)}));
     << endl;
     << "sr = sigma ray, gr = gitFan ray, sc = Sigma cone" << endl << endl;
     << "Fan structure of Sigma:" << endl;
     << apply(maxCones Sigma,C->apply(numColumns rays C, r->SigmaRayHash#((rays C)_{r}))) << endl << endl;
     structure := apply(maxCones gitFan, C->( 
	       -- Walk through maximal cones of the GIT fan
	       -- Build u as sum of generators of a maximal cone
  	       u:=(rays C)*(transpose matrix {toList (numColumns rays C:1)});
	       << "u:" << endl << u << endl;
  	       << "Cone in GIT Fan:"<< endl;
	       GitCone := apply(numColumns rays C, r->gitFanRayHash#((rays C)_{r}));
	       << GitCone <<endl;
	       -- Build delta(u).
  	       P := delta(CDual, tM, pM, u);
	       -- Build normal fan of delta(u).
	       nP := normalFan P;
	       -- Analyse structure.
  	       << "Normal fan of delta(u) as subfan of Sigma:" << endl;
	       sigRayStr := apply(maxCones nP, C->apply(numColumns rays C, r->SigmaRayHash#((rays C)_{r})));
	       << sigRayStr << endl;
	       << "Coarsening structure of delta(u) as subfan of Sigma:" << endl;
	       CoarStr := apply(maxCones nP, C->apply(select(gensSigma, gs -> contains(C,gs)), sgs -> SigmaConeHash#sgs));
	       << CoarStr <<endl;
	       << endl << endl;
	       (u,GitCone,sigRayStr,CoarStr)
	       )
	  );
     L := {{"iN",iN}, {"iM",iM}, 
	  {"pN",pN}, {"pM",pM}, 
	  {"sN",sN}, {"sM",sM}, 
	  {"tN",tN}, {"tM",tM},
	  {"Sigma",Sigma},
	  {"CDual",CDual},
	  {"C",C},
	  {"gitFan",gitFan},
	  {"ppFan",ppFan},
	  {"structure",structure}};
     hashTable L
     )
	  
     
