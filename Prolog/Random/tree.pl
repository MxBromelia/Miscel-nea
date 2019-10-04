:- dynamic tree/2.

ll(bn(bn(X,Al,Y),A,Z),bn(X,Al,bn(Y,A,Z))).
rr(X,Y) :- ll(Y,X).

lr(bn(bn(X,Al,bn(Y,Alr,Z)),A,W), bn(bn(X,Al,Y),Alr,bn(Z,A,W))).
rl(bn(X,A,bn(bn(Y,Arl,Z),Ar,W)),bn(bn(X,A,Y),Arl,bn(Z,Ar,W))).		

newTree(X) :-
	not(tree(X,_)),
	assertz(tree(X, nil)).

removeTree(X) :-
	retract(tree(X,_)).

insert(X,N) :-
	tree(X,T0),
	insertT(N,T0,T),
	retract(tree(X,T0)),
	assertz(tree(X, T)).

remove(X,N) :-
	tree(X,T1),
	removeT(N,T1,T),
	retract(tree(X,T1)),
	assertz(tree(X, T)).

search(X,N) :-
	tree(X,T),
	searchT(T,N).

printTree(X) :-
	tree(X,T),
	write(X), write(":"), nl,
	printT(T).

printT(T) :- printTree(T,0).
printTree(nil, _).
printTree(bn(Left,X,Right), L) :-
	printTree(Right,succ(L)),
	writeBlank(L),
	write(X), nl,
	printTree(Left,succ(L)).

listTree(X, L) :-
	tree(X, T),
	listTree(T, [], L).

listTree(nil, L, L).
listTree(bn(Left, X, Right), R, [X|L]) :-
	listTree(Right, R, L0),
	listTree(Left, L0, L).

listTree2(X, L) :-
	tree(X, T),
	listTree2(T, [], L).

listTree2(nil, L, L).
listTree2(bn(nil,X,nil), R, [X|R]).
listTree2(bn(Left, X, Right), R, [X,N2,N1|L]) :-
	listTree2(Right, R, [N1|L0]),
	listTree2(Left, L0, [N2|L]).

listTree3(X, L) :-
	tree(X, T),
	listTree3(T, [], L).
listTree3(nil, L, L).
listTree3(bn(Left,N,Right), R, L) :-
	listTree3(Right, R, L0),
	listTree3(Left, [N|L0], L).
writeBlank(0).
writeBlank(succ(L)) :-
	write('    '),
	writeBlank(L).

insertT(N,nil,bn(nil,N,nil)) :- !.
insertT(N,bn(Left0,T,Right),bn(Left,T,Right)) :-
	N < T, !,
	insertT(N,Left0,Left).
insertT(N,bn(Left,T,Right0),bn(Left,T,Right)) :-
	T < N, !,
	insertT(N,Right0,Right).

removeT(N, bn(nil,N,nil), nil) :- !.
removeT(N, bn(Left0,N,Right), bn(Left,X,Right)) :-
	!, removeM(max,Left0,X,Left).
removeT(N, bn(nil,N,Right0), bn(nil,X,Right)) :-
	!, removeM(max,Right0,X,Right).
removeT(N, bn(Left0,T,Right), bn(Left,T,Right)) :-
	N < T, !,
	removeT(N,Left0,Left).
removeT(N, bn(Left,T,Right0), bn(Left,T,Right)) :-
	T < N, !,
	removeT(N,Right0,Right).

removeM(_,bn(nil,X,nil),X,nil).
removeM(max,bn(Left,N,Right0),X,bn(Left,N,Right)) :-
	removeM(max,Right0,X,Right).
removeM(min,bn(Left0,X,Right),X,bn(Left,X,Right)) :-
	removeM(min,Left0,X,Left).

searchT(bn(_,N,_),N) :- !.
searchT(bn(Left,T,_), N) :-
	N < T, !,
	searchT(Left, N).
searchT(bn(_,T,Right), N) :-
	T < N, !,
	searchT(Right,N).