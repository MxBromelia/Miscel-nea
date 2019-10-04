% Questao 01-------------------------------------------------------------------
reinou(paulo, 844, 878).
reinou(pedro, 878, 916).
reinou(joao, 916, 950).
reinou(cedric, 916, 950).
reinou(roberto, 950, 979).
reinou(sandro, 979, 985).
reinou(otavio, 985, 986).
reinou(marco, 986, 999).

reinava(Nome, Ano) :- reinou(Nome, Ano_i, Ano_f), Ano_i =< Ano, Ano =< Ano_f.
%------------------------------------------------------------------------------

%Questao 02--------------------------------------------------------------------
%estudante(nome, curso)
estudante(marcos, a1).
estudante(marcos, a2).

%professor(nome, curso)
professor(jose, a1).
professor(jose, a2).

%curso(nome, dia, sala)
curso(a1, 4, p1).
curso(a2, 3, p1).


checa(Prof, Aluno) :-
	professor(Prof, C1), estudante(Aluno, C1), curso(C1, _, S),
	professor(Prof, C2), estudante(Aluno, C2), curso(C2, _, S),
	C1 \= C2, !.
%------------------------------------------------------------------------------

%Questao 03--------------------------------------------------------------------
precede(abraao, ismael).
precede(abraao, isaac).
precede(isaac, esau).
precede(isaac, jaco).
precede(jaco, juda).
precede(jaco, jose).

precede(A, C) :- precede(B, C), precede(A, B). %Erro de pilha
%------------------------------------------------------------------------------

%Questao 04--------------------------------------------------------------------
%disciplina(codigo, curso)
disciplina(ma1, matematica).
disciplina(sa1, computacao).
ensina(joao, ma1).
ensina(mulher_joao, sa1).

inteligente(Prof) :- ensina(Prof, Disc), disciplina(Disc, Curso), Curso = computacao.
%------------------------------------------------------------------------------

%Questao 05--------------------------------------------------------------------
gosta(Mae, Filho) :- mae(Mae, Filho), bom(Filho).
mulher(X) :- mae(X, _).
mulher(ana).
casado(marido_ana, ana).
bom(marido_ana). %Ainda não feita
%------------------------------------------------------------------------------

%Questao 06--------------------------------------------------------------------
e_lista([]).
e_lista([_| _]).
%------------------------------------------------------------------------------

%Questao 07--------------------------------------------------------------------
tira_prim(_, [], []) :- !.
tira_prim(E, [E | Y], Y) :- !.
tira_prim(E, [X | Y], Lis) :- tira_prim(E, Y, Lis_), Lis = [X | Lis_].
%------------------------------------------------------------------------------

%Questao 08--------------------------------------------------------------------
tira_tudo(_, [], []) :- !.
tira_tudo(E, [E | Y], Lis) :- Lis = Y.
tira_tudo(E, [X | Y], Lis) :- tira_tudo(E, Y, Lis_), Lis = [X | Lis_].
%------------------------------------------------------------------------------

%Questao 09--------------------------------------------------------------------
consec(A, B, [A | Y]) :- Y = [B | _].
%------------------------------------------------------------------------------

%Questao 10--------------------------------------------------------------------
ultimo([X], X) :- !.
ultimo([ _ | Y], K) :- ultimo(Y, K).
%------------------------------------------------------------------------------

%Questao 11--------------------------------------------------------------------
ord([]) :- !.
ord([_]) :- !.
ord([ X, Y | Z]) :- X =< Y, ord([Y | Z]), !.
%------------------------------------------------------------------------------

%Questao 12--------------------------------------------------------------------
insere_ord(X, [], [X]) :- !.
insere_ord(X, [A | B], [X, A | B]) :- X =< A, !.
insere_ord(X, [A | B], Lis) :- X >= A, insere_ord(X, B, Lis_), Lis = [A | Lis_], !.
%------------------------------------------------------------------------------