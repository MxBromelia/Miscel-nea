subBag([],X).
subBag([X|Y],Bag) :-
    select(X,Bag,Bag1),
    subBag(Y,Bag1).

equalBags([],[]).
equalBags(X,Y) :-
    subBag(X,Y),
    subBag(Y,X).

select1(X,[X|L],L).
select1(X,[E|L],[E|L1]) :-
        select(X,L,L1).