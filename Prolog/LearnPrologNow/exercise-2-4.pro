word(astante, a,s,t,a,n,t,e). 
word(astoria, a,s,t,o,r,i,a). 
word(baratto, b,a,r,a,t,t,o). 
word(cobalto, c,o,b,a,l,t,o). 
word(pistola, p,i,s,t,o,l,a). 
word(statale, s,t,a,t,a,l,e).

match(2, 2, A, B) :-
	word(A, _, A2, _, _, _, _, _),
	word(B, _, B2, _, _, _, _, _),

	A2 = B2.

match(2, 4, A, B) :-
	word(A, _, A2, _, _, _, _, _),
	word(B, _, _, _, B4, _, _, _),

	A2 = B4.

match(2, 6, A, B) :-
	word(A, _, A2, _, _, _, _, _),
	word(B, _, _, _, _, _, B6, _),

	A2 = B6.

match(4, 2, A, B) :-
	word(A, _, _, _, A4, _, _, _),
	word(B, _, B2, _, _, _, _, _),

	A4 = B2.

match(4, 4, A, B) :-
	word(A, _, _, _, A4, _, _, _),
	word(B, _, _, _, B4, _, _, _),

	A4 = B4.

match(4, 6, A, B) :-
	word(A, _, _, _, A4, _, _, _),
	word(B, _, _, _, _, _, B6, _),

	A4 = B6.

match(6, 2, A, B) :-
	word(A, _, _, _, _, _, A6, _),
	word(B, _, B2, _, _, _, _, _),

	A6 = B2.

match(6, 4, A, B) :-
	word(A, _, _, _, _, _, A6, _),
	word(B, _, _, _, B4, _, _, _),

	A6 = B4.

match(6, 6, A, B) :-
	word(A, _, _, _, _, _, A6, _),
	word(B, _, _, _, _, _, B6, _),

	A6 = B6.


crossword(V1, V2, V3, H1, H2, H3) :-
	match(2, 2, V1, H1), V1 \= H1,
	match(4, 2, V1, H2), V1 \= H2,
	match(6, 2, V1, H3), V1 \= H3,

	match(2, 4, V2, H1), V2 \= H1,
	match(4, 4, V2, H2), V2 \= H2,
	match(6, 4, V2, H3), V2 \= H3,

	match(2, 6, V3, H1), V3 \= H1,
	match(4, 6, V3, H2), V3 \= H2,
	match(6, 6, V3, H3), V3 \= H3.