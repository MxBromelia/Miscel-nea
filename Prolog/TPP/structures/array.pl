make_array(N,A) :-
	functor(A,a,N).
get_element(N,A,E) :-
	arg(N,A,E).
replace_element(A,I,E,NA) :-
	argrep(A,I,E,NA).

make_array2(M,N,A) :-
	functor(A,a,M),make_rows(M,N,A).

make_rows(0,_,_) :- !.
make_rows(I,N,A) :-
	functor(R,r,N),arg(I,A,R),
	I1 is I-1,make_rows(I1,N,A).

get_element2(M,N,A,E) :-
	arg(M,A,L),
	arg(N,L,E).

argrep(Functor,Index,NewElement,NewFunctor) :-
	Functor =.. List,
	rep(List,Index,NewElement,NewList),	
	NewFunctor =.. NewList.

rep([_|Tail],0,X,[X|Tail]) :- !.
rep([E|Tail],N,X,[E|NewTail]) :-
	N1 is N-1,
	rep(Tail,N1,X,NewTail).

% EXEMPLO: HEAP SORT
heap_sort(A,N,A1) :-
	build_heap(A,N,N,A2),
	adjust_heap(A2,N,A1).

build_heap(A,I,N,A1) :-
	I > 0, !, adjust(A,I,N,A2),
	I1 is I-1,
	build_heap(A2,I1,N,A1).
build_heap(A,0,_,A).

adjust_heap(A,J,A1):-
	J > 1, !, swap(A,1,J,A2),
	J1 is J-1, adjust(A2,1,J1,A3),
	adjust_heap(A3,J1,A1).
adjust_heap(A,1,A).

adjust(A,I,J,A1) :-
	find_larger_child(A,I,J,K,Y),
	arg(I,A,X),
	X< Y, !, swap(A,I,K,A2),
	adjust(A2,K,J,A1).
adjust(A,_,_,A).

find_larger_child(A,I,J,K,Y) :-
	L is 2*I, R is 2*I + 1,
	L =< J, arg(L,A,LC),
	(R =< J, arg(R,A,RC), RC > LC, !,
	K is R, Y is RC; K is L, Y is LC).

swap(A,I,J,A1) :-
	arg(I,A,X),arg(J,A,Y),
	argrep(A,I,Y,A2),argrep(A2,J,X,A1).