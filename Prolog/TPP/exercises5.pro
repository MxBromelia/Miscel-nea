% Exercise 5.5
tribal_poem :-
	get_tribal(X),
	gerar(X,S),
	print_poem(S).

get_tribal(X) :-
	format("Escolha o grupo de palavras tribais:\n", []),
	read(N), number(N),
	tribal(N,X).

print_poem(S) :-
	format("O poema e: \n", []),
	print_verses(S).

print_verses([]) :- !.
print_verses([V|L]) :-
	print_list(V),
	print_verses(L).

print_list([]) :- nl, !.
print_list([W|V]) :-
	format("~w ", W),
	print_list(V).

gerar(L,X) :-
	X = 
		[
			[A, B1, B2, C1],
			[D, E1, E2, C2],
			[F1, F2, G],
			[H, I1, I2, C3]
		],
	select_rima(L,B1,B2,L1),
	select_rima(L1,E1,E2,L2),
	select_rima(L2,F1,F2,L3),
	select_rima(L3,I1,I2,L4),
	select_rima(L4,C1,C2,L5),
	select(C3,L5,L6),

	permutation(L6, [A,D,G,H]).

select_rima(L0,A,B,L) :-
	select(A,L0,L1),
	select(B,L1,L),
	rima(A,B).

rima(A,B) :-
	atom_chars(A,A1),
	atom_chars(B,B1),
	
	rhyme(A1,B1).

rhyme([X],[Y]) :- !, X = Y.
rhyme([X], [_|L]) :- !, rhyme([X], L).
rhyme([_|L], [X]) :- !, rhyme(L, [X]).
rhyme([_|L1],[_|L2]) :-
	rhyme(L1,L2).


tribal(1,[
	anun,
	ariten,
	bimo,
	co,
	kana,
	kura,
	kuru,
	shime,
	sicom,
	sonen,
	su,
	tama,
	te,
	unuri,
	xanadu
]).