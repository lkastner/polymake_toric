application "fan";
$M = new Matrix<Rational>([0,0,1],[1,0,1],[1,1,1],[0,1,1]);
$f=check_fan($M,new Array<Set<Int> >((new Set<Int>(0,1,3)),(new Set<Int>(1,3,2))));
$g=check_fan($M,new Array<Set<Int> >((new Set<Int>(0,1,2)),(new Set<Int>(0,2,3))));
$h=normal_fan(cube(3));
print equal_fans($f,$g);
print equal_fans($f,$f);
print equal_fans($h,$f);
print equal_fans($g,$h);
