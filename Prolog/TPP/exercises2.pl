%Question 2.12
menu(P) :-
	pizzas(P),
	%length(P, 5),
	topping1(T1),
	topping2(T2),
	prices(C),

	named(P, 'Hawaiian', P1),
	named(P, 'Marco-Polo', P2),
	named(P, 'Pepperoni', P3),
	named(P, 'Super-Supreme', P4),
	named(P, 'Ninja-Pizza', P8),

	costs(P1, C, C1, Price1), Price1 > 6.50,
	costs(P2, C1, C2, 8.50),
	costs(P3, C2, C3, 7.00),
	costs(P5, C3, C4, Price2), Price2 \= 6.50,
	costs(P7, C4, C5, Price3), Price3 \= 10.00,

	top2(P2, T2, T2A, tomato), top1(P2, T1, T1A, Top1), Top1 \= ham, 
	top2(P4, T2A, T2B, Top2), Top2 \= pineapple,
	member(P5, P), top1(P5, T1A, T1B, tuna), top2(P5, T2B, T2C, corn), 
	member(P6, P), top2(P6, T2C, T2D, olive), top1(P6, T1B, T1C, Top3), Top3 \= salami,
	member(P7, P), top2(P7, T2D, T2E, pineapple).

named(P, N, pizza(N,_,_,_)) :-
	member(pizza(N,_,_,_), P).

costs(pizza(_,_,_,Price), C0, C, Price) :-
	select(Price, C0, C).

top1(pizza(_,Top,_,_), T0, T, Top) :-
	select(Top, T0, T).

top2(pizza(_,_,Top,_), T0, T, Top) :-
	select(Top, T0, T).

pizzas([
	pizza(_,_,_,_),
	pizza(_,_,_,_),
	pizza(_,_,_,_),
	pizza(_,_,_,_),
	pizza(_,_,_,_)
]).

topping1([
	ham,
	mussels,
	prawns,
	salami,
	tuna
]).

topping2([
	avocado,
	corn,
	olive,
	pineapple,
	tomato
]).

prices([
	5.00,
	6.50,
	7.00,
	8.50,
	10.00
]).


%Question 2.13
f(X, Y) :- X > 100, Y is X-10.
f(X, Y) :- X =< 100,
	X1 is X+11,
	f(X1, Y1),
	f(Y1, Y).

%Question 2.15
%item a
deleteAll(_, [], []).
deleteAll(X, [X|L], L1) :- deleteAll(X, L, L1).
deleteAll(X, [Y|L], [Y|L1]) :- deleteAll(X, L, L1).

%item b
replaceOne(X, Y, [X|L], [Y|L]).
replaceOne(X, Y, [Z|L], [Z|L1]) :- replaceOne(X, Y, L, L1).

%item c
deleteNth(0, [_|L1], L1).
deleteNth(N, [X|L], [X|L1]) :- 
	deleteNth(N1, L, L1),
	N is N1+1.

%Question 2.16
%item a
sum([], 0).
sum([X|L], Y) :-
	sum(L, Y1),
	Y is Y1+X.

%item b
mean(L, M) :-
	sum(L, S),
	length(L, X),
	M is S/X.

%item c
rawMean(L, M) :- raw(L, 0, 0, M).

raw([], N, S, M) :- M is S / N.
raw([X|L], N, S, M) :-
	N1 is N+1,
	Sp is S+X,
	raw(L, N1, Sp, M).

%Question 2.17
alterInput([], [], []).
alterInput([X|L1], [], [X|L]) :- alterInput(L1, [], L).
alterInput([X|L1], L2, [X|L]) :- alterInput(L2, L1, L).
%Answer: Yes, they are reversible

%Question 2.18
%item a
cutLast([_], []).
cutLast([X|L], [X|L1]) :- cutLast(L, L1).

%item b
trim(0, L, L).
trim(N, [_|L], L1) :- trim(N1, L, L1), N is N1+1.

%item c
trimLast(N, L, L1) :- length(L, Len), trimLast_(N, L, Len, L1).
trimlast(N, L, L1) :- trimLast__(N, L, _, 0, L1).

trimLast_(N, _, N, []).
trimLast_(N, [X|L], Len, [X|L1]) :- trimLast_(N, L, Len_, L1), Len is Len_ + 1.

trimLast__(_, [], Len, Len, []).
trimLast__(N, [X|L], Len, Acc, L1) :-
	Acc_ is Acc + 1,
	trimLast__(N, L, Len, Acc_, L_),
	Det is Len - Acc,
	(N >= Det, L1 = L_;
	N < Det, L1 = [X|L_]).

%Question 2.19
%item a
mystery([],1).
mystery(X, 0) :- X \= [], atomic(X).
mystery([X|Y], N) :- mystery(X, Q), mystery(Y, P), Q1 is Q + 1, max(P,Q1,N).

max(A, B, A) :- A >= B.
max(A, B, B) :- A < B.
% The predicate mystery defines what is the greatest amount amount of nested lists presented in X.

%item b
strange(X,X) :- atomic(X).
strange([H|T], [H1|T1]) :- strange(H,H1), strange(T,T1).

% Question 2.20
% member(NAME,SEX,HEOGHT,WEIGHT,HOBBIES)

% item a
name_height(Name, Height) :-
	member(Name,_,Height,_,_).

name_weight(Name, Weight) :-
	member(Name,_,_,Weight,_).

name_hobbies(Name, Hobbies) :-
	member(Name,_,_,_,Hobbies).

% item b
name_hobby(Name, Hobby) :-
	member(Name,_,_,_,Hobbies),
	member(Hobby,Hobbies).

% test case knowlodge-base
member('Henry Law', male, 1.78, 75, [jogging,skiing,singing]).
member('John Doe', male, 1.75, 68, [soccer,jogging,dancing]).
member('Mary Sue', female, 1.66, 51, [tennis,soccer,singing]).
member('Jane Austin', female, 1.58, 47, [writing,singing,tennis,jogging]).
member('Joe Montana', male, 1.77, 72, [shooting]).

%Question 2.21
%emp_name(ID, NAME)
%emp_dep(ID, DEPARTMENT)
%emp_pos(ID, POSITION)
%emp_years(ID, YEARS)
%emp_salary(ID, SALARY)
name_dep(Name, Department) :-
	emp_name(Id, Name),
	emp_dep(Id, Department).

emp_manager(Name, Manager) :-
	name_dep(Name, Department),
	emp_dep(ManagerID, Department),
	emp_pos(ManagerID, manager),
	emp_name(ManagerID, Manager).

man_salary(Salary) :-
	emp_dep(Id, manager),
	emp_salary(Id, Salary).

%test case knowledge-base
emp_name(1,'Henry Law').
emp_name(2,'John Doe').
emp_name(3,'Mary Sue').
emp_name(4,'Jane Austin').
emp_name(5,'Joe Montana').

emp_dep(1, it).
emp_dep(2, marketing).
emp_dep(3, it).
emp_dep(4, marketing).
emp_dep(5, it).

emp_pos(1, developer).
emp_pos(2, creator).
emp_pos(3, manager).
emp_pos(4, manager).
emp_pos(5, developer).

emp_years(1, 3).
emp_years(2, 2).
emp_years(3, 7).
emp_years(4, 1).
emp_years(5, 3).

emp_salary(1, 1500).
emp_salary(2, 1200).
emp_salary(3, 2700).
emp_salary(4, 3000).
emp_salary(5, 2500).

%Question 2.22

guilty(X, Y) :-
	accused(X,Y),
	defense(X,Y), fail.

guilty(X,Y) :-
	accused(X,Y),
	not(defense(X,Y)),
	penalty(Y,light), fail.

guilty(X,Y) :-
	accused(X,Y),
	commit(X,Z),
	not(accused(X,Z)),
	penalty(Y, light),
	penalty(Z, heavy).

%Test case knowlodge-base
penalty(robbery, light).
penalty(assault, light).
penalty(kidnapping, heavy).
penalty(murder, heavy).	

accused(john, kidnapping).
accused(dan, robbery).
accused(jane, assault).	

defense(john, kidnapping).

commit(jane, murder).

%Question 2.23

cost(1,2,27).
cost(1,3,43).
cost(1,4,16).
cost(1,5,30).
cost(1,6,26).
cost(2,1,7).
cost(2,3,16).
cost(2,4,1).
cost(2,5,30).
cost(2,6,25).
cost(3,1,20).
cost(3,2,13).
cost(3,4,35).
cost(3,5,5).
cost(3,6,0).
cost(4,1,21).
cost(4,2,16).
cost(4,3,25).
cost(4,5,18).
cost(4,6,18).
cost(5,1,12).
cost(5,2,46).
cost(5,3,27).
cost(5,4,48).
cost(5,6,5).
cost(6,1,23).
cost(6,2,5).
cost(6,3,5).
cost(6,4,9).
cost(6,5,5).

calculate_cost([_],R,R).
calculate_cost([A,B|L],X,R) :-
	cost(A,B,C),
	X1 is X+C,
	calculate_cost([B|L],X1,R).

tsp_dec(L, R) :-
	X = [1,2,3,4,5,6],

	append(X, [1], Xa),
	calculate_cost(Xa,0,R0),
	tsp_decl(X, X, L, R0, R).

tsp_decl(X, L0, L, R0, R) :-
	next_higher_perm(X, Xg),
	Xga = [A|_],
	append(Xg,[A],Xga),
	calculate_cost(Xga,0,C),
	(
		C < R0, Rg = C, Lg = Xg
	;
		C >= R0, Rg = R0, Lg = L0
	),
	tsp_decl(Xg,Lg,L,Rg,R).
tsp_decl(_,L,L,C,C).

next_higher_perm(L, L1) :-
	higher_perm(L, L1), not(far_higher(L1,L)).

higher_perm(L, L1) :-
	permutation(L,L1), higher(L1, L).

higher([H1|_], [H|_]) :-
	H1 > H.
higher([H|T1], [H|T]) :-
	higher(T1,T).

far_higher(L1,L) :-
	higher_perm(L,L2), higher(L1, L2).
