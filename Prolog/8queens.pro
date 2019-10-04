queen(X,Y) :- X > 0, Y > 0, X < 9, Y < 9.

range(queen(X, _), queen(X, _)) :- !.
range(queen(_, Y), queen(_, Y)) :- !.
range(queen(X1, Y1), queen(X2, Y2)) :- S is (Y2 - Y1)/(X2 - X1), S =:= 1, !.
range(queen(X1, Y1), queen(X2, Y2)) :- S is (Y2 - Y1)/(X2 - X1), S =:= -1, !.

twoQueens(queen(X1,Y1), queen(X2, Y2)) :- \=(range(queen(X1,Y1), queen(X2, Y2))).