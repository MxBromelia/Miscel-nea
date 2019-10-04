%Practice 5.1
accMin([X|L], Min) :- accMin(L, X, Min).

accMin([X|L], A, Min) :- X >= A, accMin(L, A, Min).
accMin([X|L], A, Min) :- X < A, accMin(L, X, Min).
accMin([], A, A).

%Practice 5.2
scalarMult(_, [], []).
scalarMult(N, [X1|L1], [X|L]) :- X is X1*N, scalarMult(N, L1, L).

%Practice 5.3
dot(V, U, S) :- dot(V,U,0,S).
dot([],[],S,S).
dot([X|L1], [Y|L2], S0, S) :- S1 is X*Y+S0, dot(L1, L2, S1, S).