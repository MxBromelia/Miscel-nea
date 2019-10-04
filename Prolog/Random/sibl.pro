parent(homer,bart).
parent(marge,bart).
parent(homer,lisa).
parent(marge,lisa).
parent(homer,maggie).
parent(marge,maggie).

sib(X, Y) :- parent(P, X), parent(P, Y), X \= Y, X @< Y.