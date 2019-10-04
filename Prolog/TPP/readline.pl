readline(L) :-
	get0(C),
	read_chars(C,[],L1),
	reverse(L1,L).

read_chars(10,L,L) :- !.
read_chars(8,[C|L],L1) :- !,
	put(32),put(8),
	get0(C1),
	read_chars(C1,L,L1).
read_chars(C,L,L1) :-
	get0(C1),
	read_chars(C1,[C|L],L1).