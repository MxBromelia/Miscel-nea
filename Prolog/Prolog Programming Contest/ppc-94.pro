:- use_module(contestlib,[numlist/3]).
spiral(M,_,X,0,L) :-
	Y is X+M-1,
	numlist(X,Y,L).

spiral(M,N,X,I,L) :-
	I > 0, I < N,
	I1 is I-1,
	M2 is M-2,

	B is 2*(M+N-2)+1-I,
	B1 is B+1,
	spiral(M2,N,B1,I1,L1),
	append([B|L1], [X], L).

%Problem 3 - Domino

domino([stone(A,B)|S1], S) :-
	once(matchset(S1, A, B, [stone(A,B)], S)).

matchset([], _, _, S, S).

matchset(R, A, B, S0, [X1|S]) :-
	select(X, R, L),
	match(X,A,B,X1,A1),
	matchset(L, A1, B, S0, S).

matchset(R, A, B, S0, S) :-
	select(X, R, L),
	match(X,A,B,X1,B1),
	matchset(L, A, B1, [X1|S0], S).

match(stone(A,B),A,_,stone(A,B),B).
match(stone(A,B),_,B,stone(A,B),A).
match(stone(A,B),B,_,stone(B,A),A).
match(stone(A,B),_,A,stone(B,A),B).

% Problem 4 - Crosswords
crossword(Puzzle) :-
	wordsToFit(Puzzle,PuzzleChars),
	matchwords(PuzzleChars,Solution).

wordsToFit([],[]) :- !.
wordsToFit([Word|RestWords], [Chars:_|RestChars]) :-
	atom_chars(Word,Chars),
	wordsToChar(RestWords,RestChars).

matchWords(PuzzleChars,Solution) :- matchwords(PuzzleChars, [], Solution).

matchwords([], Solution, Solution).
matchwords([Word|Rest], PartialSolution, Solution) :-
	.

matchchars(X, [], X:h:(1,1)).
matchchars(X, [], X:v:(1,1)).
matchchars(

size(5).
black(1,3).
black(2,3).
black(3,2).
black(4,3).
black(5,1).
black(5,5).

%Problem 5

loop(Loop) :- Loop
	.

cicle(A,P) :- path(A,A,P).

path(A,B,[A,B]) :- arrow(A,B).
path(A,C, [A|L]) :- arrow(A,B), path(B,C,L).

path2(A,B,R,[A,B|R]) :- arrow(A,B).
path2(A,C,R,L) :- arrow(B,C), \+member(A,R),path2(A,B,[A|R],L).

arrow(a,b).
arrow(b,c).
arrow(c,c).
arrow(a,d).
arrow(d,a).