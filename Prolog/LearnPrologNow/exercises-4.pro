second(X, [_,X|_]).

swap12([X,Y|Z], [Y,X|Z]).

tran(eins,one). 
tran(zwei,two). 
tran(drei,three). 
tran(vier,four). 
tran(fuenf,five). 
tran(sechs,six). 
tran(sieben,seven). 
tran(acht,eight). 
tran(neun,nine).

listtran([],[]).
listtran([X|G],[Y|E]) :-
	tran(X, Y),
	listtran(G,E).

twice([],[]).
twice([X|L], [X,X|L1]) :-
	twice(L, L1).