%Exercise 10.3
split([],[],[]) :- !.
split([X|L], [X|L1], L2) :- X >= 0, !, split(L, L1, L2).
split([X|L], L1, [X|L2]) :- X < 0, split(L, L1, L2).

%Exercise 10.4
directTrain(saarbruecken,dudweiler). 
directTrain(forbach,saarbruecken). 
directTrain(freyming,forbach). 
directTrain(stAvold,freyming). 
directTrain(fahlquemont,stAvold). 
directTrain(metz,fahlquemont). 
directTrain(nancy,metz).

directTravel(A,B) :- directTrain(A,B).

travel(A,B,[A,B]) :-
	directTravel(A,B).
travel(A,C,[A|P]) :-
	directTravel(A,B),
	travel(B,C, P).

route(A,B,R) :-
	travel(A,B,R).
route(A,B,R) :-
	travel(B,A,R1),
	reverse(R1,R).