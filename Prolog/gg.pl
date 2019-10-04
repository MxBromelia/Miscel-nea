:- use_module(library(clpfd)).

find(L,N) :-
	length(L,N),
	get(L,[1,2,3,4,5,6,7,8,9]),
	sum(L,_,S),
	S #= 4*N + 5*_,

	setof(X, (A^ B^ L1^ select(A,L,L1), member(B,L1), A+B mod 5 #= 3), []).

get([A|L],R) :-
	select(A,R,R1),
	get(L,R1).
get([],_).