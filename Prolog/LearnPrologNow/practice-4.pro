%Practice 4.1
combine1([], [], []).
combine1([X|L1], [], [X|L1]).
combine1([], [Y|L2], [Y|L2]).
combine1([X|L1], [Y|L2], [X,Y|L]) :- combine1(L2, L1, L).

combine2([], [], []).
combine2([X|L1], [], [[X,nomatch]|L]) :- combine2(L1, [], L).
combine2([], [Y|L2], [[nomatch,Y]|L]) :- combine2([], L2, L).
combine2([X|L1], [Y|L2], [[X,Y]|L]) :- combine2(L1, L2, L).

combine3([], [], []).
combine3([X|L1], [], [j(X, nomatch)|L]) :- combine3(L1, [], L).
combine3([], [Y|L2], [j(nomatch, Y)|L]) :- combine3([], L2, L).
combine3([X|L1], [Y|L2], [j(X,Y)|L]) :- combine3(L1, L2, L).