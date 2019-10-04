%Wikibooks example problem
trip_plan(
	[
		votes(1, cairo, V1),
		votes(2, london, V2),
		votes(3, beijing, V3),
		votes(4, moscow, V4),
		votes(5, mumbai, V5),
		votes(6, nairobi, V6),
		votes(7, jakarta, V7)
	]
).

total([4,2,2,1,1,0,0]).

solve(S) :-
	trip_plan(S),
	total(T0),

	candidate(S, A), city(A, beijing),
	candidate(S, B), city(B, cairo),

	candidate(S,C), city(C, moscow),
	(votes(C, 4, T1, T2); votes(C, 0, T1, T2)),

	candidate(S, D), city(D, jakarta),
	

	candidate(S, E), votes(E, 2),
	next(S, E, E1), votes(E1, 0, T3, T4),

	candidate(S, F), votes(F, 2, T4, T5),
	next(S, F, F1), votes(F1, 0, T5, T6),

	candidate(S, G), city(G, london),
	(more_votes(G, D, 1) ; more_votes(A, D, T6, _, 1)),
	more_votes(B, D, T2, T3, _),
	not(equal_votes(A,B, T0, T1)).

candidate(S, X) :- member(X, S).

city(votes(_,C,_), C).

equal_votes(A,B,V0,V) :-
	votes(A, X, V0, V1),
	votes(B, X, V1, V).

%votes(votes(_,_,N), N, _, _).
votes(votes(_,_,N), N, V0, V) :-
	select(N, V0, V).

more_votes(A, B, T0, T, N) :-
	votes(A, N1, T0, T1),
	votes(B, N2, T1, T),
	N1 > N2,
	N is N1-N2.

next(S, X, Y) :-
	append(_, [X,Y|_], S).