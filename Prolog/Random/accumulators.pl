reverse(X, Rev) :- reverse(X, [], Rev).

reverse([], Rev, Rev).     % Nothing left to reverse.
reverse([H|T], Prev, Rev) :-
    reverse(T, [H|Prev], Rev).

l(List, N) :-
  length(List, 0, N).
length([], N, N).       % Second argument is the accumulator.
length([_|T], L, N) :-
    L1 is L + 1,
    length(T, L1, N).