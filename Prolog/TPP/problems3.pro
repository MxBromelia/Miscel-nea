%Problem 3.3
sort_tree(L, T) :- insert_tree(L, nil, T).

insert_tree([], T, T).
insert_tree([X|R], S, T) :-
	insert_elemt(X,S,S1), insert_tree(R,S1,T).

insert_elemt(X,nil,bt(nil,X,nil)).
insert_elemt(X, bt(Left,Y,Right), bt(Left1,Y,Right)) :-
	X < Y, insert_elemt(X, Left, Left1).
insert_elemt(X, bt(Left,Y,Right), bt(Left,Y,Right1)) :-
	X >= Y, insert_elemt(X, Right, Right1).

%Problem 3.4
reverse([], L, L).
reverse([X|A], B, L) :- reverse(A, [X|B], L).

next_higher_perm(L, L1) :-
	reverse(L, [], L2),
	append(A, [X,Y|B], L2), X > Y,
	append(A, [X], C),
	append(A1, [U|B1], C), U > Y,
	append(A1, [Y|B1], B2),
	reverse([U|B], B2, L1).

%problem 3.5
solve([S,E,N,D], [M,O,R,E], [M,O,N,E,Y]) :-
	M = 1, L = [0,2,3,4,5,6,7,8,9],
	select(S,L,L1), S>0, (C3 = 0; C3 = 1),
	O is S+M+C3-10*M, select(O, L1, L2),
	select(E, L2, L3), (C2 = 0; C2 = 1),
	N is E+O+C2-10*C3, select(N, L3, L4),
	(C1 = 0; C1 = 1),
	R is E+10*C2-(N+C1), select(R, L4, L5),
	select(D, L5, L6),
	Y is D+E-10*C1, select(Y,L6,_).