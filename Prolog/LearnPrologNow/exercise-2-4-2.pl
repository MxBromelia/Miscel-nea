word(astante, a,s,t,a,n,t,e). 
word(astoria, a,s,t,o,r,i,a). 
word(baratto, b,a,r,a,t,t,o). 
word(cobalto, c,o,b,a,l,t,o). 
word(pistola, p,i,s,t,o,l,a). 
word(statale, s,t,a,t,a,l,e).

letterList(W, L) :-
	word(W, W1, W2, W3, W4, W5, W6, W7),
	L = [W1, W2, W3, W4, W5, W6, W7].

listItem([X | _], 1, X).
listItem([_ | L], N, V) :-
	N > 1,
	N1 is N-1,
	listItem(L, N1, V1),
	V = V1.

match(NA, NB, A, B) :-
	letterList(A, LA),
	letterList(B, LB),

	listItem(LA, NA, W),
	listItem(LB, NB, W).

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