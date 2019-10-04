estrada(a, b, 25).
estrada(a, d, 23).
estrada(b, c, 19).
estrada(b, e, 32).
estrada(c, d, 14).
estrada(c, f, 28).
estrada(d, f, 30).
estrada(e, f, 26).

rota(A, B, D) :- estrada(A, B, D).
rota(A, B, D) :- estrada(A, C, D1), rota(C, B, D2), D is D1 + D2.