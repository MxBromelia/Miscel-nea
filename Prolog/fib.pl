fib(1,1).
fib(2,1).
fib(N,F) :-
	N > 2,
    N1 is N-1,
    N2 is N-2,
    fib(N1,F1),
    fib(N2,F2),
    F is F1 + F2.

    remove(X, [], []).
    remove(X, L, L1) :-
        L = [X|L1].
    remove(X, L, L3) :-
        L = [E|L1],
        \+ X = E,
        remove(X, L1, L2),
        L3 = [E|L2].

    remove1(_,[],[]).
    remove1(X,[X|L1],L1).
    remove1(X,[E|L1],[E|L2]) :-
        \+ X = E,
        remove1(X,L1,L2).

        