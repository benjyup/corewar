.name "all in one"
.comment "Made to test all valid cases"

live %1

ld 1,r2
ld %1,r2

st r1, 1
st r1, r2

add r1, r2, r3

sub r1, r2, r3

and r1, r2, r3
and 512, r2, r3
and %-1, r2, r3
and r1, 2, r3
and 1, 2, r3
and %1, 2, r3
and r1, %2, r3
and 1, %2, r3
and %1, %2, r3

or r1, r2, r3
or 1, r2, r3
or %1, r2, r3
or r1, 2, r3
or 1, 2, r3
or %1, 2, r3
or r1, %2, r3
or 1, %2, r3
or %1, %2, r3

xor r1, r2, r3
xor 1, r2, r3
xor %1, r2, r3
xor r1, 2, r3
xor 1, 2, r3
xor %1, 2, r3
xor r1, %2, r3
xor 1, %2, r3
xor %1, %2, r3

fork %1

zjmp %1

sti r1, r2, r3
sti r1, 2, r3
sti r1, %2, r3
sti r1, r2, %3
sti r1, 2, %3
sti r1, %2, %3

ldi r1, r2, r3
ldi 1, r2, r3
ldi %1, r2, r3
ldi r1, %2, r3
ldi 1, %2, r3
ldi %1, %2, r3

lld 1, r2
lld %1, r2

lldi r1, r2, r3
lldi 1, r2, r3
lldi %1, r2, r3
lldi r1, %2, r3
lldi 1, %2, r3
lldi %1, %2, r3

lfork %1

aff r1
