:- op(700, xfx, gte).
:- op(700, xfx, lt).

%Defining Operators
gte(cost(_,_,X), cost(_,_,Y)) :-
	!, X >= Y.
gte(X,Y) :- X >= Y.

lt(cost(_,_,X), cost(_,_,Y)) :-
	!, X < Y.
lt(X,Y) :- X < Y.

%Defining TSP heurisitic
tsp_solve(X) :-
	travel_salesman(N, X, L),
	merge_sort(L, R1),
	least_cost_linking(R1, N, R, C),
	write('rota: '), write(R), nl,
	write('custo: '), write(C).

least_cost_linking(L, N, R, C) :-
	member(cost(From,To,_),L),
	R0 = [E|_],
	length(R0, N),
	chain_select(L, [From,To], From, To, R0),
	append(R0,[E],R),
	calculate_cost(L, R, 0, C).

chain_select(_, R, _, _, R).
chain_select(L, S, From, To, R) :-
	C = cost(To, T, _),
	select(C, L, L1),
	chain_insert(C, S, last, S1),
	chain_select(L1, S1, From, T, R).
chain_select(L, S, From, To, R) :-
	C = cost(T, From, _),
	select(C, L, L1),
	chain_insert(C, S, first, S1),
	chain_select(L1, S1, T, To, R).

calculate_cost(_, [_], S, S).	
calculate_cost(R, [X,Y|L], P, S) :-
	member(cost(X,Y,C),R),
	P1 is P + C,
	calculate_cost(R, [Y|L], P1, S).

chain_insert(cost(From, To, _), [A|L], first, [From, A|L]) :-
	To = A,
	not(member(From, L)).
chain_insert(cost(From, To, _), L, last, L1) :-
	reverse(L, [A|R]),
	A = From,
	not(member(To, R)),
	reverse([To, A|R], L1).

%Defining Sort Algorithm
merge_sort(L,R) :-
	L = [_,_|_], !,
	merge(L, L1, L2),
	merge_sort(L1, R1),
	merge_sort(L2, R2),
	combine(R1, R2, R).
merge_sort([X],[X]) :- !.
merge_sort([],[]).

merge([X,Y|L], [X|L1], [Y|L2]) :-
	!, merge(L, L1, L2).
merge([X], [X], []) :- !.	
merge([],[], []).

combine(L,[],L) :- !.
combine([],L,L) :- !.
combine([X|L1], [Y|L2], [X|L]) :-
	X lt Y,
	combine(L1, [Y|L2], L), !.
combine([X|L1], [Y|L2], [Y|L]) :-
	X gte Y,
	combine([X|L1], L2, L).

travel_salesman(6, num,
	[
		cost(1,2,27), cost(1,3,43), cost(1,4,16), cost(1,5,30), cost(1,6,26),
		cost(2,1,7),  cost(2,3,16), cost(2,4,1),  cost(2,5,30), cost(2,6,25),
		cost(3,1,20), cost(3,2,13), cost(3,4,35), cost(3,5,5),  cost(3,6,0),
		cost(4,1,21), cost(4,2,16), cost(4,3,25), cost(4,5,18), cost(4,6,18),
		cost(5,1,12), cost(5,2,46), cost(5,3,27), cost(5,4,48), cost(5,6,5),
		cost(6,1,23), cost(6,2,5),  cost(6,3,5),  cost(6,4,9),  cost(6,5,5)
	]
).

travel_salesman(3, let,
	[
		cost(a,b,1), cost(a,c,3),
		cost(b,a,2), cost(b,c,1),
		cost(c,a,3), cost(c,b,2)
	]
).