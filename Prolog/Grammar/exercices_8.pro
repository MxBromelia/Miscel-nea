s --> np(subject, X), vp(X).

np(X, singular) --> det(singular, Y), n(X, singular, Y).
np(X, plural) --> n(X, plural, _).

vp(X) --> v(X),np(object, _).
vp(X) --> v(X).

det(_, _)--> [the].
det(singular, non_vogal)--> [a].
det(singular, vogal) --> [an].

n(subject, singular, non_vogal) --> [woman].
n(subject, singular, non_vogal) --> [man].
n(subject, plural, non_vogal) --> [women].
n(subject, plural, non_vogal) --> [men].

n(object, singular, vogal) --> [apple].
n(object, singular, non_vogal) --> [pear].

v(singular) --> [eats].
v(singular) --> [knows].
v(plural) --> [eat].
v(plural) --> [know].

s_x --> kanga(_, _, _).
kanga(V,R,Q)  -->  roo(V,R),jumps(Q,Q),{marsupial(V,R,Q)}.