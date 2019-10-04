%Exercise 6.1
%'Killing bugs with a bazooka' way
doubled --> eq(X), eq(Y), {X = Y}.
eq([X]) --> one(X).
eq([X|Y]) --> one(X), eq(Y).
one(X) --> [X].

%a more simple approach
double(X) :- append(Y, Y, X).

%Exercise 6.2
palindrome(AB, BA) :- reverse(AB, BA).

%Execise 6.3
toptail([_|In], Out) :- poplast(In, Out).

poplast([_], []).
poplast([X|L1], [X|L]) :- poplast(L1,L).

%Exercise 6.4
lastrev(L,X) :- reverse(L, [X|_]).

lastrec([X], X).
lastrec([_|L], Y) :- lastrec(L, Y).

%Exercise 6.5
swapfl([Fst|List1], [Lst|List2]) :- swapfl(List1, Fst, Lst, List2).

swapfl([A], B, A, [B]).
swapfl([X|L1], A, B, [X|L2]) :- swapfl(L1, A, B, L2).

%Exercise 6.6

nbhood(
	nbs(
		nb(H1, N1, P1),
		nb(H2, N2, P2),
		nb(H3, N3, P3)
	)
).

zebra(S) :-
	nbhood(S),

	lives(A, S), nationality(A, englishman), housecolor(A,red),
	lives(B, S), nationality(B, spanish), pet(B, jaguar),
	lives(C, S), nationality(C, japanese), livesRight(C, M, S), pet(M, snail),
	lives(M, S), livesRight(N, M, S), housecolor(N, blue),
	lives(F, S), housecolor(F,green),
	lives(X, S), pet(X,zebra).

lives(X, nbs(X,_,_)).
lives(X, nbs(_,X,_)).
lives(X, nbs(_,_,X)).

housecolor(nb(H,_,_), H).

nationality(nb(_,N,_), N).

pet(nb(_,_,P), P).

livesRight(B,A,nbs(A,B,_)).
livesRight(C,B,nbs(_,B,C)).