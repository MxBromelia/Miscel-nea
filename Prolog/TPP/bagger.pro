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

fill_bags([], S:_, S).
fill_bags(L, B:N, S) :-
	select(A,L,L1),
	item(Size,A),
	M is N+Size,
	M =< 19,
	fill_bags(L1, [A|B]:M,S).
fill_bags(L, B:N, [B,S]) :-
	select(A,L,_),
	item(Size,A),
	M is N+Size,
	M > 19,
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