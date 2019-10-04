ll(bn(bn(X,Al,Y),Z),Bn(X,Al,bn(Y,A,Z))).
rr(X,Y) :- ll(Y,X).

lr(bn(bn(X,Al,bn(Y,Alr,Z))), bn(bn(X,Al,Y),Alr,bn(Z,A,W))).
rl(bn(X,A,bn(bn(Y,Arl,Z),Ar,W)),bn(bn(X,A,Y),Arl,bn(Z,Ar,W))).

testcase(1,bn(bn(bn(nl,1,nl),2,nl),3,nl)).
testcase(2,bn(nl,1,bn(nl,2,bn(nl,3,nl)))).
testcase(3,bn(bn(nl,1,bn(nl,2,nl)),3,nl)).

% Estrutura: bt(Left,Node,Right)-I

insert(nil-z, E, 1, bt(nil-z,E,nil-z)-0) :- !.
insert(bt(Left,X,Right)-I,E, B, bt(Left1,X,Right1)-I) :-
	(
		E < X, !,
		Right1 = Right,
		insert(Left,E, B1, Left0),
		I is E+B1,
		balance(Left0,Left1)
	;
		E > X, !,
		Left1 = Left,
		insert(Right,E, B0, Right0),
		I is E-B1,
		balance(Right0,Right1)
	).

balance

insertlist(X,[],X).
insertlist(X,[E|L],Y) :-
	insert(X,E,Z),!,
	insertlist(Z,L,Y).

printTree(nil-z,_) :- nl, !.
printTree(bt(Left,E,Right)-_,N) :-
	printTree(Right,seq(N)),
	whitespace(N),print(E),
	printTree(Left,seq(N)).

whitespace(0) :- !.
whitespace(seq(N)) :-
	write('\t'),
	whitespace(N).