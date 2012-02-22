application "fan";
$f = normal_fan(cube(2));
$t = cast<ToricVariety>($f);
$v = new Vector(3,4,6,5);
$w = new Vector(4.2,5,6,3);
$z = $f->RAYS->col(1);
$D = $t->add("DIVISOR",COEFFICIENTS=>$v);
$D2 = $t->add("DIVISOR",COEFFICIENTS=>$w);
$D3 = $t->add("DIVISOR",COEFFICIENTS=>$z);
print $D->INTEGRAL;
print $D2->INTEGRAL;
print $D3->INTEGRAL;
print $D->PRINCIPAL;
print $D2->PRINCIPAL;
print $D3->PRINCIPAL;

