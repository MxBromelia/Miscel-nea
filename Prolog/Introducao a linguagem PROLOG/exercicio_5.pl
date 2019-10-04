ultimo([X], X).
ultimo([_|Y], Z) :- ultimo(Y, Z), !.

tamanho([], 0).
tamanho([_|Y], Z) :- tamanho(Y, Zp), Z is Zp+1, !.

soma([], 0).
soma([X|Y], Z) :- soma(Y, Zp), Z is Zp + X.

max([X], X).
max([X|Y], Z) :- max(Y, Zp), X =< Zp, Z is Zp.
max([X|Y], Z) :- max(Y, Zp), X > Zp, Z is X.

anexa([], B, B).
anexa([X|A], B, [X|C]) :- anexa(A, B, C).

inv([], []).
inv([X|Y], Z) :- inv(Y, Zp), Xp = [X], anexa(Zp, Xp, Z).

sim(X) :-inv(X, Y), X = Y.

d(0, zero).
d(1, um).
d(2, dois).
d(3, tres).
d(4, quatro).
d(5, cinco).
d(6, seis).
d(7, sete).
d(8, oito).
d(9, nove).

txt([], []).
txt([X|Y], Z) :- d(X, Xt), txt(Y, Zt), Z = [Xt|Zt].

estrada(1, a, b).
estrada(2, a, d).
estrada(3, b, c).
estrada(4, c, d).
estrada(5, b, e).
estrada(6, c, f).
estrada(7, d, f).
estrada(8, e, f).

rota(A, B, R) :- estrada(X, A, B), R = [X].
rota(A, B, R) :- rota(A, C, Rp1), rota(C, B, Rp2), merge(Rp1, Rp2, R).

ponto(_, _).
declive(ponto(Ax, Ay), ponto(Bx, By), D) :- D is (By-Ay)/(Bx-Ax).
retangulo(ponto(Ax,Ay),ponto(Bx,By),ponto(Cx,Cy),ponto(Dx,Dy)) :- Bx - Ax =:= Cx- Dx, Dy - Ay =:= Cy - By.