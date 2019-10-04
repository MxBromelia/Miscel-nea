knight_tour :-
	get_parameters(N,X,Y),
	mount_table(N,T),
	solve(X,Y,T).

get_parameters(N,X,Y) :-
	write('Defina a quantidade de blocos em cada tabuleiro: '), nl,
	read(N), number(N),
	write('Defina as coordenadas iniciais do cavalo(formato(X,Y).): '), nl,
	read((X,Y)), range(X,1-N), range(Y,1-N).

range(X, A-B) :-
	A =< X, X =< B.

mount_table(N,T) :-
	length(T,N),
	mount_lists(N,T).

mount_lists(_, []) :- !.
mount_lists(N, [E|L]) :-
	length(E,N),
	mount_lists(N,L).

solve(X,Y,T) :-
	fill_cell(X,Y,T),
	fill_table(T,(X,Y)).

fill_table(Table, Coords) :-
	not_filled(Table), !,
	move(Coords,Table,NewCoords),
	fill_table(Table, NewCoords).
fill_table(_,_).

not_filled(T) :-
	member(L,T),
	member(E,L),
	var(E).

move((X,Y), T, (NewX,NewY)) :-
	knight(MoveX,MoveY),
	NewX is X + MoveX,
	NewY is Y + MoveY,

	fill_cell(X,Y,T).

fill_cell(X,Y,T) :-
	nth1(X,T,L),
	nth1(Y,L,k).

knight(-2,-1).
knight(-2,1).
knight(-1,-2).
knight(-1,2).
knight(1,-2).
knight(1,2).
knight(2,-1).
knight(2,1).