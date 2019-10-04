connected(1,2).
connected(3,4).
connected(5,6).
connected(7,8).
connected(9,10).
connected(12,13).
connected(13,14).
connected(15,16).
connected(17,18).
connected(19,20).
connected(4,1).
connected(6,3).
connected(4,7).
connected(6,11).
connected(14,9).
connected(11,15).
connected(16,12).
connected(14,17).
connected(16,19).

path(X, Y) :- connected(X, Y).
path(X, Z) :- connected(X, Y), path(Y, Z).

%----------------------------------------------

byCar(auckland,hamilton). 
byCar(hamilton,raglan). 
byCar(valmont,saarbruecken). 
byCar(valmont,metz). 

byTrain(metz,frankfurt). 
byTrain(saarbruecken,frankfurt). 
byTrain(metz,paris). 
byTrain(saarbruecken,paris). 

byPlane(frankfurt,bangkok). 
byPlane(frankfurt,singapore). 
byPlane(paris,losAngeles). 
byPlane(bangkok,auckland). 
byPlane(singapore,auckland). 
byPlane(losAngeles,auckland).

directTravel(X, Y, car) :- byCar(X, Y).
directTravel(X, Y, train) :- byTrain(X, Y).
directTravel(X, Y, plane) :- byPlane(X, Y).

travel(X, Y) :- directTravel(X, Y, _).
travel(X, Z) :- directTravel(X, Y, _), travel(Y, Z).

travel(A, B, go(A, B, T)) :- directTravel(A, B, T).
travel(A, C, go(A, B, T, Route)) :-
   directTravel(A,B, T),
   travel(B, C, Route).