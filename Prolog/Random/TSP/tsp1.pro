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
tsp_solve(R) :-
	travel_salesman(N, L),
	merge_sort(L, R1),
	least_cost_linking(R1, N, R),
	write(R).

% Tentativa 1: Fazer duas listas para acompanhar o crescimento do caminho,
% e parasse quando cada cidade tivesse um ponto de partida e chegada
%
% Problema: Não leva contexto em consideração, o que pode causar ciclos
% menores que os desejados, não possibilitando uma viagem completa.
%
% Possível resolução: Implementar um algoritmo semelhante ao problema dos
% dominós.
%
% Problemas na resolução proposta: Fim do select acumulado
least_cost_linking(L, N, R) :-
	least_cost_linking(L, N, [], [], R).

least_cost_linking(L, N, From, To, []) :-
	From = To,
	n_list(N, [], S),
	S = From, !.
least_cost_linking(L, N, From, To, [X|R]	) :-
	select_acc(X, L, L1),
	X = cost(X_f, X_t, _),
	insert_path(X_f, From, From_i),
	insert_path(X_t, To, To_i),
	least_cost_linking(L1, N, From_i, To_i, R).

select_acc(H, [H|T], T).
select_acc(X, [_|T], T1) :-
	select_acc(X, T, T1).

insert_path(X, [], [X]) :- !.
insert_path(X, [Y|L], [X,Y|L]) :-
	X < Y, !.
insert_path(X, [Y|L], [Y|L1]) :-
	X > Y,
	insert_path(X, L, L1).

n_list(0, R, R) :- !.
n_list(N, L, R) :-
	N1 is N-1,
	n_list(N1,[N|L], R).

%Defining Sort Algorithm
tsp_sort(L,	R) :-
	travel_salesman(L),
	merge_sort(L, R).

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

travel_salesman(6,
	[
		cost(1,2,27), cost(1,3,43), cost(1,4,16), cost(1,5,30), cost(1,6,26),
		cost(2,1,7),  cost(2,3,16), cost(2,4,1),  cost(2,5,30), cost(2,6,25),
		cost(3,1,20), cost(3,2,13), cost(3,4,35), cost(3,5,5),  cost(3,6,0),
		cost(4,1,21), cost(4,2,16), cost(4,3,25), cost(4,5,18), cost(4,6,18),
		cost(5,1,12), cost(5,2,46), cost(5,3,27), cost(5,4,48), cost(5,6,5),
		cost(6,1,23), cost(6,2,5),  cost(6,3,5),  cost(6,4,9),  cost(6,5,5)
	]
).