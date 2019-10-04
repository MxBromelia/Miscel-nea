uiva(cao).

tem(X,gato) -> \+ tem(X,rato).
sono_leve(X) -> tem(X,Y), not(uiva(Y)).

tem(joao,X) :- (X=cao;X=gato).