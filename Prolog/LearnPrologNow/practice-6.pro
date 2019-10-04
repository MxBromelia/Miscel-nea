member(X, L) :- append(_, [X|_], L).

set(InList,OutList) :- set(InList, [], OutList).

set([], _, []).
set([X|L1], M, L) :-
	member(X,M),
	set(L1, [X|M], L).
set([X|L1], M, [X|L]) :-
	not(member(X,M)),
	set(L1, [X|M], L).

flatten([],[]).
flatten([[]],[]).
flatten([[A|B]|C], [A|L]) :- flatten([B|C], L).
flatten([A|B1], [A|B]) :- flatten(B1, B).

flat([],[]).

flat([A|B], [A|B1]) :-
	atomic(A),
	flat(B, B1).

flat([A|B], [A1|B1]) :-
	is_list(A),
	flat(A, [A1|Aft]),
	append(Aft,X,B1),
	flat(B,X).

flattening([], R, Rev) :- reverse(R, Rev).
flattening([A|B], R, F) :-
	first_atom(A, H, T),
	flattening(T, R, _),
	flattening(B, [H|R], F).

first_atom(X, X, []) :- atomic(X).
first_atom([A|B], A, B) :- atomic(A).
first_atom([A|B], H, [B|T]) :- is_list(A), first_atom(A, H, T).

flat_ap([], []).
flat_ap([A|B], [A|B1]) :-
	atomic(A), A \= [],
	flat_ap(B,B1).
flat_ap([A|B], L) :-
	flat_ap(A, A1),
	flat_ap(B, B1),
	append(A1, B1, L).