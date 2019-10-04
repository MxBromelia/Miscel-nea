pai(adao,cain).
pai(adao,abel).
pai(adao,seth).
pai(seth,enos).

filho(X, Y) :- pai(Y, X).

avo(X,Y) :- pai(X,Z), pai(Z,Y).
neto(X, Y) :- avo(Y, X).

irmao(X,Y) :- pai(Z, X), pai(Z, Y), \=(X, Y).

tio(X, Y) :- pai(Z,Y), irmao(Z, X).
sobrinho(Y, Z) :- tio(Z, Y).