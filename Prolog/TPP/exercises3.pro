%Exercise 3.8
merge_sort(L,S) :-
	m_sort(L, S).

m_sort([],[]).
m_sort([X], [X]).
m_sort(L, S) :-
	L = [_,_|_],
	merge(L, L1, L2),
	m_sort(L1, S1),
	m_sort(L2, S2),
	combine(S1, S2, S).

merge([], [], []).
merge([X], [X], []).
merge([X,Y|L], [X|L1], [Y|L2]) :- merge(L, L1, L2).

combine([],[],[]).
combine([X|L1], [], [X|L]) :- combine(L1, [], L).
combine([X|L1], [Y|L2], [X|L]) :- X < Y, combine([Y|L2], L1, L).
combine([X|L1], [Y|L2], [Y|L]) :- X >= Y, combine([X|L1], L2, L).

%Exercise 3.10
tolist(T, L) :- tolist(T, [], L).
tolist(nil, L, L).
tolist(bn(Left,X,Right), R, L) :-
	tolist(Right, R, L1),
	tolist(Left, [X|L1], L).

%Exercise 3.11
fill(X,N,L) :-
	length(L,N),
	append([X],L1,L),
	append(L2,[X],L),
	L1=L2.

fill2(X, N, L) :- fill2(X, N, 1, L).
fill2(X, N, N, [X]) :- !.
fill2(X, N, M, [X|L]) :-
	M1 is M+1,
	fill2(X, N, M1, L).

%Exercise 3.12
solve([C,R,O,S,S],[R,O,A,D],[D,A,N,G,E,R]) :-
	D = 1, L = [0,2,3,4,5,6,7,8,9],				%D
	select(C, L, L1), C > 0, (C4 = 0; C4 = 1),	%C, C4
	A is C + C4 - 10*D, select(A, L1, L2),		%A
	select(R, L2, L3), (C3 = 0; C3 = 1),		%R, C3
	N is 2*R + C3 - 10*C4, select(N, L3, L4),	%N
	select(O, L4, L5), (C2 = 0; C2 = 1),		%O, C2
	G is O + O + C2 - 10*C3, select(G, L5, L6),	%G
	select(S, L6, L7), (C1 = 0; C1 = 1),		%S, C1
	E is S + A + C1 - 10*C2, select(E, L7, L8),	%E
	select(D, L8, _).							%D

%Exercise 3.13
assemblySolution([X, Y, Z]) :-
	parts(S0),
	[X, Y, Z] = [[Q1, Q2, Q3], [Q4, Q5, Q6], [Q7, Q8, Q9]],

	select(P1, S0, S1), assembly(P2, P1, lr, Q2, Q1), select(P2, S1, S2),
	assembly(P3, P2, lr, Q3, Q2), select(P3, S2, S3), 
	assembly(P4, P1, ud, Q4, Q1), select(P4, S3, S4), 
	assembly(P5, P2, ud, Q5, Q2), assembly(P5, P4, lr, Q5, Q4), select(P5, S4, S5), 
	assembly(P6, P3, ud, Q6, Q3), assembly(P6, P5, lr, Q6, Q5), select(P6, S5, S6), 
	assembly(P7, P4, ud, Q7, Q4), select(P7, S6, S7), 
	assembly(P8, P5, ud, Q8, Q5), assembly(P8, P7, lr, Q8, Q7), select(P8, S7, S8), 
	assembly(P9, P6, ud, Q9, Q6), assembly(P9, P8, lr, Q9, Q8), select(P9, S8, _).

parts([
	piece((-,b), (+,c), (+,d), (-,a)),
	piece((+,a), (+,d), (-,c), (-,d)),
	piece((-,c), (+,b), (+,d), (-,d)),
	piece((-,d), (-,c), (+,d), (+,b)),
	piece((+,b), (-,c), (-,a), (+,d)),
	piece((-,a), (-,d), (+,c), (+,b)),
	piece((-,b), (+,c), (+,b), (-,a)),
	piece((-,a), (-,c), (+,a), (+,b)),
	piece((-,b), (+,a), (+,d), (-,c))
]).

assembly(A, B, T, A1, B1) :-
	spin(A, A1),
	spin(B, B1),
	match(A1, B1, T).

match(piece(_,_,_,(SL,VL)), piece(_,(SR,VR),_,_), lr) :-
	((SL,SR) = (+,-);
	(SL,SR) = (-,+)),

	VL = VR.

match(piece((SU,VU),_,_,_), piece(_,_,(SD,VD),_), ud) :-
	((SU,SD) = (+,-);
	(SU,SD) = (-,+)),

	VU = VD.

spin(piece(A,B,C,D),piece(A,B,C,D)).
spin(piece(A,B,C,D),piece(B,C,D,A)).
spin(piece(A,B,C,D),piece(C,D,A,B)).
spin(piece(A,B,C,D),piece(D,A,B,C)).

% Exercise 3.14
bagger(X,L) :-
	inverted_insertion_sort(X,Xs),
	fill_bags(Xs,[]:0, L).

inverted_insertion_sort([],[]).
inverted_insertion_sort([H|T],L1) :-
	inverted_insertion_sort(T,L2),insert(H,L2,L1).

insert(X,[],[X]).
insert(X,[H|T], [X,H|T]) :-
	item(Nx,X),
	item(Nh,H),
	Nx >= Nh.
insert(X, [H|T], [H|T1]) :-
	item(Nx,X),
	item(Nh,H),
	Nx < Nh,
	insert(X, T, T1).

fill_bags([], S:_, [S]) :- !.
fill_bags(L, B:N, S) :-
	select(A,L,L1),
	item(Size,A),
	M is N+Size,
	M =< 19, !,
	fill_bags(L1, [A|B]:M,S).	
fill_bags(L, B:N, [B|S]) :-
	select(A,L,_),
	item(Size,A),
	M is N+Size,
	M > 19, !,
	fill_bags(L, []:0, S).

item(1,grape).
item(3,apple).
item(3,banana).
item(3,orange).
item(3,pear).
item(5,avocado).
item(5,melon).
item(5,pineapple).
item(5,watermelon).