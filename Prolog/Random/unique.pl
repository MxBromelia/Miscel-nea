nlist(X, [X|L]) :-
	X > 0, !,
	X1 is X-1,
	nlist(X1, L).
nlist(0, []).

unique(L) :- select(A,L,L1), 
	select(B,L1,_),
	A=B, !, fail.
unique(_).