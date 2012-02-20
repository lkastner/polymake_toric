application "fan";

# Testing Chow Quotient:
$ring = new Ring(qw(a b c d e f g h));
($x000, $x001, $x010, $x011, $x100, $x101, $x110, $x111) = $ring->variables;
$g = $x000*$x000*$x111*$x111 + $x001*$x001*$x110*$x110 + $x010*$x010*$x101*$x101 + $x011*$x011*$x100*$x100;
$g = $g - 2*($x000*$x001*$x110*$x111 + $x000*$x010*$x101*$x111 + $x000*$x100*$x011*$x111 + $x001*$x010*$x101*$x110 + $x001*$x100*$x011*$x110 + $x010*$x100*$x011*$x101);
$g = $g + 4*($x000*$x011*$x101*$x110 + $x001*$x010*$x100*$x111);
$htv = chow_quotient($g);
$htv = load("hyperdet.htv");

$amb = $htv;
$rel = $htv->HYPERSURFACE->[0]->RELEVANT_CONES;
$map = new Map<Vector<Rational>, Int>;
$i = 0;
foreach my $r (@{$amb->RAYS}){
	print $r;
	$map->{$r} = $i;
	$i++;
}
@relc = ();
foreach my $c (@{$rel->MAXIMAL_CONES}){
	push @relc, new Set<Int>(map{$map->{$rel->RAYS->[$_]}} @$c);
}
print @relc;
$s = $relc[0];
map($s+=$_, @relc);
$ambmc = $amb->MAXIMAL_CONES;
@ambmc = @$ambmc;
$cs = (new Set<Int>([0..($amb->RAYS->rows-1)]))-$s;
print $cs;
@relc = map((new Cone<Rational>(RAYS=>$amb->RAYS->minor($_, All))), @relc);
@non_bad = grep(($cs * $_)->size == 0, @ambmc);
print @non_bad;
foreach my $t (@$cs){
	my @cont = grep(incl((new Set<Int>($t)), $_) == -1, @ambmc);
	my $nc = new Set<Int>($cont[0]);
	map($nc += (new Set<Int>($_)), @cont);
	$nc -= $cs;
	$nc -= new Set<Int>($t);
	print $nc, "\n";
	$new_cone = new Cone<Rational>(INPUT_RAYS=>$amb->RAYS->minor($nc, All));
	print $new_cone->RAYS->rows," ", $new_cone->INPUT_RAYS->rows, "\n";
	my @check = map(included_polyhedra($_,$new_cone), @relc);
	print @check, "\n";
	push @non_bad, $nc;
	print @cont, "\n\n";
	
}
$f = new PolyhedralFan<Rational>(INPUT_RAYS=>$amb->RAYS, INPUT_CONES=>\@non_bad);
$namb = cast<ToricVariety>($f);
$neqn = $htv->EQUATION;
$nhtv = new HypersurfaceInTV(EQUATION=>$neqn, AMBIENT_TV=>$namb);
print $nhtv->RELEVANT_CONES->N_MAXIMAL_CONES;
#$p = load("cool.poly");
#$minkp = new Matrix<Rational>($p->MINKOWSKI_SUMMAND_CONE->EQUATIONS);
#$eqs = new Matrix<Rational>($p->GRAPH->EDGE_DIRECTIONS);
#$count = 0;
#@factors = ();
#foreach my $e (@$eqs){
#	my $factor = new Rational(1);
#   my $test = primitive(eliminate_denominators($e));
#	for(my $i = 0; $i < $e->dim; $i++){
#		if($e->[$i] != 0){
#			$factor = (new Rational($test->[$i]))/(new Rational($e->[$i]));
#			last;
#		}
#	}
#	print $e, " ", $test, " factor: ", $factor, "\n";
#	$minkp->col($count) *= $factor;
#	push @factors, $factor;
#	$count++;
#}
#$eqs = primitive(eliminate_denominators($eqs));
#$eq = new Matrix<Rational>(zero_vector($minkp->rows) | $minkp);
#$ineq = new Matrix<Rational>(-ones_vector($minkp->cols) | dense(unit_matrix($minkp->cols)));
#$newMink = new Polytope<Rational>(EQUATIONS=>$eq, INEQUALITIES=>$ineq);
#$q = new Vector<Rational>($newMink->VERTICES->[0]->slice(1));
#$i = 0;
#foreach my $f (@factors){
#	$q->[$i] *= $f;
#	$i++;
#}
#$ms = $p->MINKOWSKI_SUMMAND_POINT($q);
