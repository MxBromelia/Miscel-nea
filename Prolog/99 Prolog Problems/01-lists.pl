% 1.01 (*) Find the last element of a list.
my_last([N],N) :- !.
my_last([_|L],E) :-
	my_last(L,E).

last(X) --> [X].
last(X) --> nlast, last(X).

nlast --> [_].

% 1.02 (*) Find the last but one element of a list.
pre_last([X,_],X) :- !.
pre_last([_,E|L],W) :-
	pre_last([E|L],W).


% 1.03 (*) Find the K'th element of a list.
element_at(1,[A|_],A) :- !.
element_at(X,[_|L],E) :-
	element_at(X1,L,E),
	X is X1+1.


% 1.04 (*) Find the number of elements of a list.
len([],0) :- !.
len([_|L],N) :-
	length(L,N1),
	N is N1+1.


% 1.05 (*) Reverse a list.
reverse([],L,L) :- !.
reverse([A|L],Lr,R) :-
	reverse(L,[A|Lr],R).


% 1.06 (*) Find out whether a list is a palindrome.
palindrome(X) :-
	reverse(X,Y),
	X = Y.


% 1.07 (**) Flatten a nested list structure.
my_flatten([],[]) :- !.
my_flatten([A|L],[A|F]) :-
	\+ is_list(A), !,
	my_flatten(L,F).
my_flatten([La|L],F) :-
	my_flatten(La,Lb),
	append(Lb,F0,F),
	my_flatten(L,F0).


% 1.08 (**) Eliminate consecutive duplicates of list elements.	
compress([A|L],B) :-
	compress(L,A,B).
compress([X|L],X,R) :-
	compress(L,X,R), !.
compress([Y|L],X,[X|R]) :-
	compress(L,Y,R), !.
compress([],A,[A]).


% 1.09 (**) Pack consecutive duplicates of list elements into sublists.
pack([X|L],B) :-
	pack(L,[X],B).

pack([A|L1],[B|R],L) :-
	A = B, !,
	pack(L1,[A,B|R],L).
pack([A|B],[C|D],[[C|D]|L]) :-
	\+ A = C, !,
	pack(B,[A],L).
pack([],L,[L]).


% 1.10 (*) Run-length encoding of a list.
encode(L,R) :-
	pack(L,L1),
	agroup(L1,R).

agroup([A|L],[B|R]) :-
	num_dupl(A,B), !,
	agroup(L,R).
agroup([],[]).

num_dupl([A|L],[N,A]) :-
	num_dupl(L,[M,A]), !,
	N is M+1.
num_dupl([],[0,_]).


% 1.11 (*) Modified run-length encoding.
encode_modified(L,R) :-
	encode(L,L1),
	modify_encoding(L1,R).

modify_encoding([[A,X]|L],[Y|R]) :-
	(
		A = 1, !, Y = X
	;
		Y = [A,X]
	),
	!, modify_encoding(L,R).
modify_encoding([],[]).


% 1.12 (**) Decode a run-length encoded list.
de_encode([[N,E]|L],R) :-
	fill(N,LE,E),
	de_encode(L,L1),
	append(LE,L1,R).
de_encode([],[]).

fill(N,L,E) :-
	length(L,N),
	L = [E|LA],
	append(LB,[E],L),
	LA = LB.


% 1.14 (*) Duplicate the elements of a list.
dupli([X|L],[X,X|R]):-
	!, dupli(L,R).
dupli([],[]).


% 1.15 (**) Duplicate the elements of a list a given number of times.
dupli([X|L],R,N) :-
	fill(N,S,X), !,
	append(S,L1,R),
	dupli(L,L1,N).
dupli([],[],_).


% 1.16 (**) Drop every N'th element from a list.
drop(L,N,R) :-
	drop(L,1,N,R).

drop([A|L],M,N,[A|R]) :-
	M < N, !,
	M1 is M+1,
	drop(L,M1,N,R).
drop([_|L],N,N,R) :-
	!, drop(L,1,N,R).
drop([],_,_,[]).


% 1.17 (*) Split a list into two parts; the length of the first part is given.
split(L,N,L1,L2) :-
	length(L1,N),
	append(L1,L2,L).


% 1.18 (**) Extract a slice from a list.
slice([_|L],A,B,R) :-
	A > 1, !,
	A1 is A-1,
	B1 is B-1,
	slice(L, A1, B1, R).
slice([E|L], 1, N, [E|R]) :-
	N > 0,
	N1 is N-1, !,
	slice(L,1,N1,R).
slice(_, 1, 0, []).


% 1.19 (**) Rotate a list N places to the left.
rotate(L,N,R) :-
	N > 0, !,
	length(L1,N),
	append(L2,L1,L),
	append(L1,L2,R).
rotate(L,N,R) :-
	N1 is -N,
	length(L1,N1),
	append(L1,L2,L),
	append(L2,L1,R).


% 1.20 (*) Remove the K'th element from a list.
remove_at(E,[A|L],N,[A|R]) :-
	N > 1, !,
	N1 is N-1,
	remove_at(E,L,N1,R).
remove_at(E,[E|L],1,L).


% 1.21 (*) Insert an element at a given position into a list.
insert_at(X,[E|L],N,[E|R]) :-
	N > 1, !,
	N1 is N-1,
	insert_at(X,L,N1,R).
insert_at(X,[E|L],1,[X,E|L]).


% 1.22 (*) Create a list containing all integers within a given range.
range(X,Y,[X|L]) :-
	X < Y, !,
	X1 is X+1,
	range(X1,Y,L).
range(Y,Y,[Y]).


% 1.23 (**) Extract a given number of randomly selected elements from a list.
rnd_select(L,N,[E|S]) :-
	N > 0, !,
	length(L,Num),
	random_between(1,Num,Rnd),
	remove_at(E,L,Rnd,L1),
	N1 is N-1,
	rnd_select(L1,N1,S).
rnd_select(_,0,[]).


% 1.24 (*) Lotto: Draw N different random numbers from the set 1..M.
lotto(N,Max,L) :-
	range(1,Max,S),
	rnd_select(S,N,L).


% 1.25 (*) Generate a random permutation of the elements of a list.
rnd_permut(L,R) :-
	length(L,N),
	rnd_select(L,N,R).


% 1.26 (**) Generate the combinations of K distinct objects chosen from the N elements of a list
combination(N,L,[E|R]) :-
	N > 0, !,
	N1 is N-1,
	select_acc(E,L,L1),
	combination(N1,L1,R).
combination(0,_,[]).

select_acc(A,B,C) :- select_acc(A,B,C,[]).
select_acc(E,[E|L],L,[]).
select_acc(E,[A|L],S,[A|R]) :-
	select_acc(E,L,S,R).

combination_select(N,L,[E|R],S) :-
	N > 0,
	N1 is N-1, !,
	select_acc(E,L,L1),
	combination_select(N1,L1,R,S).
combination_select(0,S,[],S).

combination_s(Num,List,[El|Tail],Rest) :-
	Num > 0,
	N1 is Num-1, !,
	select_acc(El,List,List1,Before),
	append(Before,Rest0,Rest),
	combination_s(N1,List1,Tail,Rest0).
combination_s(0,Rest,[],Rest).


% 1.27 (**) Group the elements of a set into disjoint subsets.

% a) In how many ways can a group of 9 people work in 3 disjoint subgroups of 2, 3 and 4 persons?
% Write a predicate that generates all the possibilities via backtracking.
group3(L,L1,L2,L3) :-
	combination_s(2,L,L1,R1),
	combination_s(3,R1,L2,R2),
	combination_s(4,R2,L3,_).

% b) Generalize the above predicate in a way that we can specify a list of group sizes and the predicate will return a list of groups.
group(Group,[NGroup|TGroup],[HList|TList]) :-
	combination_s(NGroup,Group,HList,Rest),
	group(Rest,TGroup,TList).
group(_,[],[]).


% 1.28 (**) Sorting a list of lists according to length of sublists

% a) We suppose that a list (InList) contains elements that are lists themselves. 
% The objective is to sort the elements of InList according to their length.
% E.g. short lists first, longer lists later, or vice versa.
lsort(NestedLists,SortedNest) :-
	list_length(NestedLists,NestedLists_Length),
	length_sort(NestedLists_Length,NestedLists_Sorted),
	list_length(SortedNest,NestedLists_Sorted).

list_length([],[]) :- !.
list_length([List|Tail],[List-N|Tail_N]) :-
	length(List,N),
	list_length(Tail,Tail_N).

length_sort(L1,L2) :-
  insert_sort_intern(L1,[],L2).
 
insert_sort_intern([],L,L).
insert_sort_intern([H|T],L1,L) :-
  insert(L1,H,L2),
  insert_sort_intern(T,L2,L).
 
insert([],X,[X]).
insert([EH-H|T],EX-X,[EX-X,EH-H|T]) :-
  X =< H,
  !.
insert([H|T],X,[H|T2]) :-
  insert(T,X,T2).

% b) Again, we suppose that a list (InList) contains elements that are lists themselves.
% But this time the objective is to sort the elements of InList according to their length frequency;
% i.e. in the default, where sorting is done ascendingly, lists with rare lengths are placed first,
% others with a more frequent length come later.

lfsort(NestedLists,SortedNest) :-
	list_length_frequencies(NestedLists,NestedLists_Frequency),
	list_length(NestedLists_Frequency,NestedLists_Length),
	length_sort(NestedLists_Length,NestedLists_Sorted),
	list_length(SortedLists,NestedLists_Sorted),
	append_all(SortedLists,SortedNest).

list_length_frequencies([],[]) :- !.
list_length_frequencies([El|List],[Nest|NestL]) :-
	length(El,N),
	select_same_lengths(N,[El|List],Nest,Rest),
	list_length_frequencies(Rest,NestL).

select_same_lengths(N,List,[E|Set],Rest) :-
	length(E,N),
	select(E,List,List1), !,
	select_same_lengths(N,List1,Set,Rest).
select_same_lengths(_,Rest,[],Rest).

append_all([El1,El2|List],Append) :-
	append(El1,El2,El12), !,
	append_all([El12|List],Append).
append_all(List,List).