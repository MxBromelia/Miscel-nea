all(X,Y).
all(X,[H|T]) :-
    X = H,
    Y = T,
    all(not(X),Y).
(all(not(X),Y)).