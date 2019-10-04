rptst :-
	permutation([1,2,3,4,5,6],X),
	X = [A|_],
	append(X,[A],Y),
	calculate_cost(Y,0,C),
	write('perm: '), write(X), nl,
	write('cost: '), write(C), nl.

rptst2 :-
	repeat,
		append(1, [],L),
		length(L,5).

rptst3(_).
rptst3(X) :-
	permutation(X, XP),
	write(XP),
	rptst3(XP).

calculate_cost([_],R,R).
calculate_cost([A,B|L],X,R) :-
	cost(A,B,C),
	X1 is X+C,
	calculate_cost([B|L],X1,R).

tsp_dec(L, R) :-
	X = [1,2,3,4,5,6],

	append(X, [1], Xa),
	calculate_cost(Xa,0,R0),
	tsp_decl(X, X, L, R0, R).

tsp_decl(X, L0, L, R0, R) :-
	next_higher_perm(X, Xg),
	Xga = [A|_],
	append(Xg,[A],Xga),
	calculate_cost(Xga,0,C),
	(
		C < R0, Rg = C, Lg = Xg
	;
		C >= R0, Rg = R0, Lg = L0
	),
	tsp_decl(Xg,Lg,L,Rg,R).
tsp_decl(_,L,L,C,C).

next_higher_perm(L, L1) :-
	higher_perm(L, L1), not(far_higher(L1,L)).

higher_perm(L, L1) :-
	permutation(L,L1), higher(L1, L).

higher([H1|_], [H|_]) :-
	H1 > H.
higher([H|T1], [H|T]) :-
	higher(T1,T).

far_higher(L1,L) :-
	higher_perm(L,L2), higher(L1, L2).

cost(1,2,27).
cost(1,3,43).
cost(1,4,16).
cost(1,5,30).
cost(1,6,26).
cost(2,1,7).
cost(2,3,16).
cost(2,4,1).
cost(2,5,30).
cost(2,6,25).
cost(3,1,20).
cost(3,2,13).
cost(3,4,35).
cost(3,5,5).
cost(3,6,0).
cost(4,1,21).
cost(4,2,16).
cost(4,3,25).
cost(4,5,18).
cost(4,6,18).
cost(5,1,12).
cost(5,2,46).
cost(5,3,27).
cost(5,4,48).
cost(5,6,5).
cost(6,1,23).
cost(6,2,5).
cost(6,3,5).
cost(6,4,9).
cost(6,5,5).