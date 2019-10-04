w(a).
w(b).

m(j).

s(k, j).

d(a,j).
d(b,j).

p(X) :- m(X).
p(X) :- w(X).

l(X, Y) :- f(X,Y).
l(X, Y) :- p(X).

f(Y,Z) :- m(Y) , s(Z, Y).
f(Y,Z) :- m(Y) , d(Z, Y).