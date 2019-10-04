:- module(contestlib,
	  [sublist/2,
	   write_elements/1,
	   writeN/2,
	   for/3,
	   numlist/3,
	   int_width/2,
	   write_int/2,
	   map/3]).

%Checks whether R contanis S, only if,
% being P and Q elements of R and S,
% if, P appears before Q in R,
% the same happens in S
%Example: sublist([1,2,3,4,5], [1,3,5]) --> true
%Example: sublist([1,2,3,4,5], [5,1,2]) --> false
%Example: sublist([1,2], L) --> L = [1,2], L=[1], L=[2], L=[]
sublist([],[]).
sublist([X|R],[X|S]) :- sublist(R,S).
sublist([_|R],S) :- sublist(R,S).

%Write all elements of an list in-sequence without separation
%Example: write_elements([h,e,l,l,o,w,o,r,l,d]) --> helloworld
write_elements([]).
write_elements([X|R]) :- write(X), write(' '), write_elements(R).

%Write C for N times. Both C and N must be explicit
%Example: writeN(3,d) --> ddd
writeN(N,C) :-
	( N > 0 ->
	    M is N - 1,
	    write(C),
	    writeN(M,C)
	;
	    true
	).

%Through backtracking, unifies K with all the values between I and J
%Example: for(X, 1, 3) --> X = 1; X = 2; X = 3; false
for(I,I,J) :- I =< J.
for(K,I,J) :- I < J,
	I1 is I + 1,
	for(K,I1,J).

%Creates a list containing integer numbers in range [I,J] in List
%Both I and J must be explicit
%Example: numlist(1,5,L) --> L = [1,2,3,4,5]
numlist(I,J,List) :-
	( I =< J ->
	    List = [I|Rest],
	    I1 is I + 1,
	    numlist(I1,J,Rest)
	;
	    List = []
	).

int_width(N,Width) :-
	( N > 9 ->
	    M is N // 10,
	    int_width(M,WidthM),
	    Width is WidthM + 1
	;
	    Width = 1
	).

write_int(Int,Width) :-
	int_width(Int,WidthInt),
	Spaces is Width - WidthInt,
	writeN(Spaces,' '),
	write(Int).


map([],_,[]).
map([X|R],C,[CX|CR]) :-
	call(C,X,CX),
	map(R,C,CR).