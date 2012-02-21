application "fan";

# Testing Chow Quotient:
#$ring = new Ring(qw(a b c d e f g h));
#($x000, $x001, $x010, $x011, $x100, $x101, $x110, $x111) = $ring->variables;
#$g = $x000*$x000*$x111*$x111 + $x001*$x001*$x110*$x110 + $x010*$x010*$x101*$x101 + $x011*$x011*$x100*$x100;
#$g = $g - 2*($x000*$x001*$x110*$x111 + $x000*$x010*$x101*$x111 + $x000*$x100*$x011*$x111 + $x001*$x010*$x101*$x110 + $x001*$x100*$x011*$x110 + $x010*$x100*$x011*$x101);
#$g = $g + 4*($x000*$x011*$x101*$x110 + $x001*$x010*$x100*$x111);
#$htv = chow_quotient($g);
$htv = load("hyperdet.tv");

#$amb = $htv;
#$rel = $htv->HYPERSURFACE->[0]->RELEVANT_CONES;
#$map = new Map<Vector<Rational>, Int>;
#$i = 0;
#foreach my $r (@{$amb->RAYS}){
#	print $r;
#	$map->{$r} = $i;
#	$i++;
#}
#@relc = ();
#foreach my $c (@{$rel->MAXIMAL_CONES}){
#	push @relc, new Set<Int>(map{$map->{$rel->RAYS->[$_]}} @$c);
#}
#print @relc;
#$s = $relc[0];
#map($s+=$_, @relc);
#$ambmc = $amb->MAXIMAL_CONES;
#@ambmc = @$ambmc;
#$cs = (new Set<Int>([0..($amb->RAYS->rows-1)]))-$s;
#print $cs;
#@relc = map((new Cone<Rational>(RAYS=>$amb->RAYS->minor($_, All))), @relc);
#@non_bad = grep(($cs * $_)->size == 0, @ambmc);
#print @non_bad;
#foreach my $t (@$cs){
#	my @cont = grep(incl((new Set<Int>($t)), $_) == -1, @ambmc);
#	my $nc = new Set<Int>($cont[0]);
#	map($nc += (new Set<Int>($_)), @cont);
#	$nc -= $cs;
#	$nc -= new Set<Int>($t);
#	print $nc, "\n";
#	$new_cone = new Cone<Rational>(INPUT_RAYS=>$amb->RAYS->minor($nc, All));
#	print $new_cone->RAYS->rows," ", $new_cone->INPUT_RAYS->rows, "\n";
#	my @check = map(included_polyhedra($_,$new_cone), @relc);
#	print @check, "\n";
#	push @non_bad, $nc;
#	print @cont, "\n\n";
#	
#}
#$f = new PolyhedralFan<Rational>(INPUT_RAYS=>$amb->RAYS, INPUT_CONES=>\@non_bad);
#$nhtv = cast<ToricVariety>($f);
#$hs = $nhtv->add("HYPERSURFACE", EQUATION=>$htv->HYPERSURFACE->[0]->EQUATION);
#print $nhtv->HYPERSURFACE->[0]->RELEVANT_CONES->N_MAXIMAL_CONES;
$nhtv = load("hyperdet_new.tv");
print equal_fans($htv->HYPERSURFACE->[0]->RELEVANT_CONES, $nhtv->HYPERSURFACE->[0]->RELEVANT_CONES);
$p = $nhtv->GENERATING_POLYTOPE->NICE_MINKOWSKI_SUMMAND;
print $p->VERTICES;
print $p->REFLEXIVE;
