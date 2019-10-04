:- use_module(tree,[newTree/1,removeTree/1,insert/2,remove/2,search/2,printTree/2]).
soma_dois :-
	write('Insira o primeiro numero:'), nl,
	read(X), number(X),
	write('Insira o segundo numero:'), nl,
	read(Y), number(Y),
	Z is X+Y,
	write('O Resultado e '), write(Z), nl,
	write('Deseja realizar outra soma?'), nl,
	read(n).
soma_dois :- soma_dois.

menu(Opts, Preds) :-
	repeat,
		show_options(Opts),
		get_choice(Preds, Continue),
	test_for_termination(Continue).

show_options(Options) :- show_options(Options,1).

show_options([Opt|L],X) :-
	format("~d. ~w\n", [X,Opt]),
	Y is X+1, !,
	show_options(L,Y).
show_options([],_) :- !.

get_choice(Preds, Continue) :-
	get0(X),
	number(X), N is X - 48,
	(
		nth1(N,Preds,Run),!,
		Run,
		Continue = 1
	;
		Continue = 0
	).

test_for_termination(Continue) :-
	Continue = 0.

test_menu(1) :-
	menu(['opt 1', 'opt 2', 'opt 3'],
		[
			format("you chose option 1 \n",[]),
			format("you chose option 2 \n",[]),
			format("you chose option 3 \n",[])
		]
	).