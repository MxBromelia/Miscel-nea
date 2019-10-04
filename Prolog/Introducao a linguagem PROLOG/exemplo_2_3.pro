% filme(Título, Gênero, Ano, Duração)
 filme('Uma linda mulher', romance, 1990, 119).
 filme('Sexto sentido', suspense, 2001, 108).
 filme('A cor purpura', drama, 1985, 152).
 filme('Copacabana', comedia, 2001, 92).
 filme('E o vento levou', drama, 1939, 233).
 filme('Carrington', romance, 1995, 130). 

% classico(T,G) :- filme(T, G, A, D), A <= 1985.
classico(T,G,A,D) :- filme(T,G,A,D), A =< 1985. 

longo(Titulo) :- filme(Titulo, _, _, Duracao), Duracao > 150.
lancamento(Titulo, Ano) :- filme(Titulo, _, Lancou, _), Dif is Ano - Lancou, Dif < 1.