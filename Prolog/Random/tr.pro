sum([X|L], R, S) :-
	RX is R+X,
	sum(L, RX, S).
sum([],S,S).