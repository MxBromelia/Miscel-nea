s_marry :-
	get_group(H,M),
	stable_pairing(H,M,S),
	print_solution(S),
	test_for_termination.
s_marry :-
	finalize.

get_group(H,M) :-
	write('Entre o numero do grupo dos casais a serem combinados:'),
	read(N),
	test_pairings(N,H,M).

print_solution(S) :-
	write('Os casais sao:'), nl,
	print_couples(S).

print_couples([]) :- !.
print_couples([(H,M)|R]) :-
	format('~w + ~w \n', [H,M]),
	print_couples(R).

test_for_termination :-
	write('Pressione qualquer tecla para outras solucoes ou <ESC> para sair'), nl,
	get0(27).

finalize :-
	write('Sem outros arranjos.'), nl,
	write('Deseja verificar outro conjunto? <y/n>'),
	(
		read(y), !, s_marry
	;
		true
	).

stable_pairing(LH, LM, S) :-
	pairing(LH, LM, [],S0),
	simplify(S0,S).

pairing([H:P|L],M,Pairs,S) :-
	member(X,P),
	Mu = X:_,
	select(Mu,M,M0),
	Pair = (H:P,Mu),
	not(unstable(Pair,Pairs)),
	pairing(L,M0,[Pair|Pairs],S).
pairing([],[],S,S).

unstable(X,Couples) :-
	member(Y,Couples),
	conflict(X,Y).

conflict((A:PA,B:_),(C:_,D:PD)) :-
	p(PA, D, B),
	p(PD, A, C).
conflict((A:_,B:PB),(C:PC,D:_)) :-
	p(PB, C, A),
	p(PC, B, D).

p([P|_],P,_).
p([P2|_],_,P2) :- !, fail.
p([_|L],P1,P2) :- !, p(L,P1,P2).

simplify([(A:_,B:_)|L], [(A,B)|S]) :- !, simplify(L,S).
simplify([],[]).

test_pairings(1,
	[
		john:[annie,suzie,wendy],
		mark:[wendy,annie,suzie],
		tony:[wndy,suzie,annie]
	]
,
	[
		annie:[tony,john,mark],
		suzie:[mark,john,tony],
		wendy:[john,mark,tony]
	]
).
test_pairings(2,
	[
		allan:[verra,xania,zonie,wendy,yamie],
		bobby:[zonie,xania,wendy,verra,yamie],
		chris:[verra,wendy,xania,yamie,zonie],
		danny:[yamie,xania,zonie,wendy,verra],
		ersky:[yamie,xania,verra,wendy,zonie]
	]
,
	[
		xania:[allan,bobby,danny,ersky,chris],
		yamie:[ersky,danny,chris,allan,bobby],
		zonie:[danny,bobby,allan,chris,ersky],
		verra:[bobby,allan,ersky,chris,danny],
		wendy:[chris,bobby,allan,danny,ersky]
	]
).