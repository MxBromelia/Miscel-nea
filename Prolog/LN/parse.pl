parse([W|WList],Goals,Answer) :-
	valid_command(W),
	split(WList,Query,Data),
	construct(Query,Goals,Answer),
	instantiate(Goals,Data).

split(WList,Query,Data) :-
	append(Query,[where|Data],WList),!.
split(WList,WList,[]).

construct([and|Qs],Goals,Answer) :- !,
	construct(Qs,Goals,Answer).
construct([P, A|Qs], [G|Gs], [P, A, X|Ans]) :-
	match_arg(P,A,G,X),
	construct(Qs,Gs,Ans).
construct([],[],[]).

instantiate(Goals,[and|Data]) :- !,
	instantiate(Goals,Data).
instantiate(Goals,[P,A,is,C|Data]) :-
	match_arg(P, A, G, C),
	member(G,Goals),
	instantiate(Goals,Data).
instantiate(_,[]).

match_arg(P, A, G, X) :-
	schema(P, N, Args), functor(G, P, N),
	index(A,Args,I),arg(I,G,X).

index(A,[A|_],1) :- !.
index(A,[B|Args],I) :-
	A \= B,
	index(A,Args,J), I is J+1.

schema(student,2,[id,name]).
schema(test,2,[id,mark]).

valid_command(find).
valid_command(show).
valid_command(give).

example([find,student,name,and,test,mark,where,student,id,is,91-2123,and,test,id,is,91-2123]).