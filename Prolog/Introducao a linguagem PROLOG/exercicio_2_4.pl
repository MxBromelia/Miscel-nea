% pessoa(Nome, Sexo, idade, Altura, Peso)
 pessoa(ana, fem, 23, 1.55, 56.0).
 pessoa(bia, fem, 19, 1.71, 61.3).
 pessoa(ivo, masc, 19, 1.80, 70.5).
 pessoa(lia, fem, 17, 1.85, 57.3).
 pessoa(eva, fem, 28, 1.75, 68.7).
 pessoa(ary, masc, 25, 1.72, 68.9).

modelo(N) :- pessoa(N, S, I, A, P), S = fem, A > 1.7, I < 25, P < (62.1*A-44.7).