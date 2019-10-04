% Exercise 4.10
stats((Age,_), Y) :- Age >= 65, !, Y = 'age-person'.
stats((_,Status), Y) :- Status = invalid, !, Y = 'invalid'.
stats((_,Status), Y) :- Status = unemployed, !, Y = 'unemployed'.
stats((_,_), nothing).

% Exercise 4.11
song(X) :-
	bottles(X), !,
	X1 is X-1,
	song(X1).
song(-1).

bottles(X) :-
	X > 0, !,
	beerbottle(X), write(' on the wall'), nl,
	beerbottle(X), nl,
	takeone.
bottles(0) :-
	beerbottle(0), write(' on the wall'), nl.

beerbottle(X) :-
	num(X, Y),
	bot(X, B),

	write(Y), write(' '), write(B), write(' of beer').

num(X, Y) :- X > 0, !, X = Y.
num(0, 'No').

bot(X,B) :- X \= 1, !, B = bottles.
bot(1,bottle).

takeone :-
	write('You take one down and pass it around'), nl.

% Exercise 4.12

% Exercise 4.13