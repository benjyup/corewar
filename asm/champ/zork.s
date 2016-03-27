.name "zork"
.comment "just a basic living prog"

l2: sti r1,%:live, %1
and r1,%0,r1
ld %1, r2
ld %2, r3
sub r2, r3, r4
live: live %2
zjmp %-5
