enigma1255(N) :-
	table8x8(T),
	transpose(T,T0),
	max(N)
	fill(T,N,_),
	non_repetitive(T),
	disarray(T,T0).

table8x8(T) :-
	rowlist(RL),
	columnlist(CL),
	setof(Row, I^(member(I,RL),
		setof(e(I,J,_),member(J,CL),Row)),
		T).

rowlist([1,2,3,4,5,6,7,8]).
columnlist([a,b,c,d,e,f,g,h]).

transpose(TA,TB) :-
	transpose(TA,1,TB).

transpose(TA,N,[RB|TB]) :-
	setof(X,RA^(member(RA,TA),nth1(N,RA,X)),RB), !,
	N1 is N+1,
	transpose(TA,N1,TB).
transpose(_,_,[]).

max(0).
max(X) :-
	max(Y), X is Y+1.

% fill

% non_repetitive

disarray(A,B) :-
	disarray(A,A,B).

disarray([],[],[]).
disarray(List,[Ref|RefTail],[Perm|PermTail]) :-
	select(Perm,List,List1),
	Perm \= Ref,
	disarray(List1,RefTail,PermTail).