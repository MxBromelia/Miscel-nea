%Exercise 5.1
increment(X,Y) :- X is Y-1.

%Exercise 5.2
sum(A,B,C) :- C is A+B.

addone([], []).
addone([X1|L1], [X|L]) :- X is X1+1, addone(L1, L).