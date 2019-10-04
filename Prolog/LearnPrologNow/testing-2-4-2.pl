word(astante, a,s,t,a,n). 
word(astoria, a,s,t,o,r). 
word(baratto, b,a,r,a,t). 
word(cobalto, c,o,b,a,l). 
word(pistola, p,i,s,t,o). 
word(statale, s,t,a,t,a).

match(2, 2, A, B) :-
	word(A, _, A2, _, _, _),
	word(B, _, B2, _, _, _),

	A2 = B2.

match(2, 4, A, B) :-
	word(A, _, A2, _, _, _),
	word(B, _, _, _, B4, _),

	A2 = B4.

match(4, 2, A, B) :-
	word(A, _, _, _, A2, _),
	word(B, _, B2, _, _, _),

	A2 = B2.

match(4, 4, A, B) :-
	word(A, _, _, _, A2, _),
	word(B, _, _, _, B2, _),

	A2 = B2.


crossword(V1, V2, H1, H2) :-
	match(2,2, H1, V1), H1 \= V1,
	match(2,4, H2, V1), H2 \= V1,
	match(4,2, H1, V2), H1 \= V2,
	match(4,4, H2, V2), H2 \= V2.