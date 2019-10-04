fact(0, 1).
fact(N, F) :- N>0, N1 is N-1, fact(N1, F1), F is N*F1.

fact2(0, F, F).
fact2(N, A, F) :-
	N > 0,
	F1 is N*A,
	N1 is N-1,
	fact2(N1, F1, F).