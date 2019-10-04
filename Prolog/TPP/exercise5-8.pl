typo :-
	typing(W0),
	string_to_list(W0,W),
	format("Write: ~w \n", [W0]),
	read_typing(T0),
	check_error(W,T0,E),
	display_result(E).

display_result(none) :- !,
	format("Nao houve problemas de digitacao. Parabens!", []).
display_result(X) :-
	format("Houve um erro de ~w na digitacao da frase.",[X]).

read_typing([C|L]) :-
	get0(C),
	C \= 46,
	C \= 8, !,
	read_typing(L).
read_typing([]).

check_error([A|W], [B|T], E) :-
	not(error(_, [A|W],[B|T])), !,
	check_error(W,T,E).
check_error(W, T, X) :-
	error(X, W, T), !.
check_error([],[], none) :- !.

error('Letra Trocada', [X,Y|_], [Y,X|_]) :- X \= Y.
error('Letras a mais', [X|_], [Y,X|_]) :- X \= Y.
error('Letras a mais', [X], [X,_]).
error('Letra Faltando', [X,Y|_], [Y|_]) :- X \= Y.
error('Letra Faltando', [X,_], [X]).
error('Letra Errada', [X|_], [Y|_]) :- X \= Y.

adjacent_permutation([A,B|X], [B,A|X]) :- !.
adjacent_permutation([A|X], [A|Y]) :-
	adjacent_permutation(X, Y).

error_case(L1, L2) :-
	test_case(E, N, L1, L2),
	check_error(L1, L2, X),
	(
		E = X, fail
	;
		E \= X, format("caso ~d de ~w: falha. Recebeu ~w.", [N, E, X])
	).	

test_case('Letra Faltando', 1, [a,v,o,c,a,d,o], L) :-
	select(_, [a,v,o,c,a,d,o], L).
test_case('Letras a mais', 1, [a,b,a,c,a,t,e], L) :-
	select(f, L, [a,b,a,c,a,t,e]).
test_case('Letras a mais', 2, L, L) :-
	L = [r,a,c,o,o,n].
test_case('Letra Trocada', 1, L1, L2) :-
	L1 = [t,y,p,i,n,g],
	adjacent_permutation(L1, L2).

typing("O rato roeu a roupa do rei de roma").