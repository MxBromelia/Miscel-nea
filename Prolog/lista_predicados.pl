lista(p, X) :- X = [0, 1, 2, 3].
lista(q, Y) :- Y = [-1, 0, 1, 2].

p(X) :- X<3.

ap([X0 | X]) :- p(X0), ap(X).

ep([X0 | X]) :- p(X0); ap(X).