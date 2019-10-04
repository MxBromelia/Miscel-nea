insertQ(E,Q-[E|T1],Q-T1).
getQ(E,[E|Q]-Qt,Q-Qt).
appendQ(A-B,B-C,A-C).
memberQ(E1,[E2|Q]-Qt) :-
	nonvar(E1),
	(E1 = E2; memberQ(E1,Q-Qt)).
list_to_queue(L,Q-Qt) :-
	append(L,Qt,Q).

% EXAMPLE: Topographical Sort
topo_sort(Graph,List) :-
	createq(Graph,Queue),
	t_sort(Graph,Queue,List).

createq(G,Q-Qt) :-
	setof(X,minimal(X,G),L),
	append(L,Qt,Q).

minimal(X,G) :-
	member(X:_,G), not(member(_:X,G)).

t_sort([],[]-[],[]) :- !.
t_sort(G,[X|Q]-Qt,[X|L]) :-
	find_successors(X,G,G1,Qt-Qs),
	t_sort(G1,Q-Qs,L).

find_successors(X,G,G1,Q-Qt) :-
	select(X:Y,G,G2),!,
	(member(_:Y,G2),!,Q=Q1;Q=[Y|Q1]),
	find_successors(X,G2,G1,Q1-Qt).
find_successors(_,G,G,Q-Q).

graph([ics:is1,dma:ps2,dma:se1,sda:ps2,dsa:se1,dsa:co1,is1:is2,is1:ps2,
	is1:se1,co1:co2,is2:pm,is2:is3,ps2:is3,co2:os,pm:cp,is3:cp,os:cp]).