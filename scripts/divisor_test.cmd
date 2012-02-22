application "fan";
$v = new Vector(3,4,6);
$D = new TDivisor(COEFFICIENTS=>$v);
print $D->INTEGRAL;
