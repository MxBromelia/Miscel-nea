word(abcde, a, b, c, d, e).
word(ebacd, e, b, a, c, d).
word(cdabe, c, d, a, b, e).
word(dceba, d, c, e, b, a).

word(asa, a, s, a).
word(oso, o, s, o).

match(2, 2, word(A, A1, A2, A3), word(B, B1, B2, B3)) :- A2 = B2.

crossword(A, B) :-
	V1 = word(A, A1, A2, A3),
	H1 = word(B, B1, B2, B3),

	match(2, 2, V1, H1).