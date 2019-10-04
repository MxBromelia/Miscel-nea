%	Estrutura: bt(Left,Node,Right)-I

insert_avl(X,nil-z,bt(nil-z,X,nil-z)-0) :- !.
insert_avl(X,bt(L-I,A,R)-IA,NewTree) :-
	X =< A,!,
	insert_avl(X,L-I,NL-NI),
	balance(1,IA,I,NI,bt(NL-NI,A,R),NewTree).
insert_avl(X,bt(L,A,R-I)-IA,NewTree) :-
	X > A,
	insert_avl(X,R-I,NR-NI),
	balance(2,IA,I,NI,bt(L,A,NR-NI),NewTree).

%	Sem rebalanceamento requerido
balance(S,I,IA,NI,NewTree,NewTree-NIA) :-
	NI * (NI-I) =:= 0, !, NIA = IA;
	IA =:= 0,!, NIA = S;
	IA + S =:= 3, !, NIA = 0.
%	Rebalanceamento por rotacao simples a direita
balance(1,1,0,1,bt(bt(LB,B,RB)-1,A,RA),
				bt(LB,B,bt(RB,A,RA)-0)-0).
%	Rebalanceamento por rotacao dupla a direita
balance(1,1,0,2,bt(bt(LB,B,bt(LC,C,RC)-IC)-2,A,RA),
				bt(br(LB,B,LC)-IB,C,bt(RC,A,RA)-IA)-0) :-
	IC =:= 0, IA = 0, IB = 0, !;
			IA is (IC+1) mod 3,
			IB is (IA+1) mod 3.
%	Rebalanceamento por rotacao simples a esquerda
balance(2,2,0,2,bt(LA,A,bt(LB,B,RB)-2),
				bt(bt(LA,A,LB)-0,B,RB)-0).
%	Rebalanceamento por rotacao dupla a esquerda
balance(2,2,0,1,bt(LA,A,bt(bt(LC,C,RC)-IC),B,RB)-1,
				bt(bt(LA,A,LC)-IA,C,bt(RC,B,RB)-IB)-0) :-
	IC =:= 0, IA = 0, IB = 0, !;
			IB is (IC+1) mod 3,
			IA is (IB+1) mod 3.