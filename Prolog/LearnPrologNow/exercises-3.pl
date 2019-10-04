directlyln(katarina, olga).
directlyln(olga, natasha).
directlyln(natasha, irina).

in(A, B) :- directlyln(A, B).
in(A, C) :- directlyln(A, B), in(B, C).

directTrain(saarbruecken,dudweiler). 
directTrain(forbach,saarbruecken). 
directTrain(freyming,forbach). 
directTrain(stAvold,freyming). 
directTrain(fahlquemont,stAvold). 
directTrain(metz,fahlquemont). 
directTrain(nancy,metz).

travelFromTo(X, Y) :- directTrain(X, Y).
travelFromTo(X, Z) :- directTrain(X, Y), travelFromTo(Y, Z).

succ_row(0, 0).
succ_row(X, succ(Y)) :- X > 0, X1 is X-1, succ_row(X1, Y).

greater_than(succ(_), 0) :- !.
greater_than(succ(X), succ(Y)) :- greater_than(X, Y).

swap(leaf(X), leaf(X)).
swap(tree(X, Y), tree(Yrev, Xrev)) :- swap(X, Xrev), swap(Y, Yrev).