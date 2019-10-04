musician_solution(S) :-
	band_soloists(S),
	first(X, S), plays(X, piano),
	order_mbers(Y,Z,S),
		named(Y, john), plays(Y, sax),
		country(Z, australia),
	order_mbers(Y1,Z1,S),
		named(Y1, mark), country(Y1, us),
		plays(Z1, violin),
	member(U,S), country(U,japan),
	member(V,S), named(V,sam).

band_soloists(band(soloist(N1,C1,I1),
	soloist(N2,C2,I2), soloist(N3,C3,I3))).

named(soloist(N,_,_), N).
country(soloist(_,C,_), C).
plays(soloist(_,_,I), I).
first(X, band(X,_,_)).
order_mbers(X,Y,band(X,Y,_)).
order_mbers(X,Z,band(X,_,Z)).
order_mbers(Y,Z,band(_,Y,Z)).
member(X, band(X,_,_)).
member(Y, band(_,Y,_)).
member(Z, band(_,_,Z)).