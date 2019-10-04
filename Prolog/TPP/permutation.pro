permutation([],[]).
permutation(L, [H|T]) :- select(H,L,R),permutation(R,T).

select(H, [H|T], T).
select(X, [H|T], [H|T1]) :- select(X,T,T1).