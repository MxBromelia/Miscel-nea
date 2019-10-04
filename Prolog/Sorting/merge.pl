merge_sort(L,R) :-
	L = [_,_|_], !,
	merge(L, L1, L2),
	merge_sort(L1, R1),
	merge_sort(L2, R2),
	combine(R1, R2, R).
merge_sort([X],[X]) :- !.
merge_sort([],[]).

merge([X,Y|L], [X|L1], [Y|L2]) :-
	!, merge(L, L1, L2).
merge([X], [X], []) :- !.	
merge([],[], []).

combine(L,[],L).
combine([],L,L).
combine([X|L1], [Y|L2], [X|L]) :-
	X < Y,
	combine(L1, [Y|L2], L).
combine([X|L1], [Y|L2], [Y|L]) :-
	X >= Y,
	combine([X|L1], L2, L).