sat(Variables,Clauses) :- true.

bruteforce(Id,Var) :-
	clauseset(Id,Var,ClauseSet),
	rep_arrange(Var,[0,1]),
	setof(Clause,(member(Clause,ClauseSet),test(Clause)),ClauseSet).

rep_arrange([],_).
rep_arrange([El|List],Set) :-
	member(El,Set),
	rep_arrange(List,Set).

test([Clause|_]) :-
	(Clause = 1; Clause = (\+0)), !.
test([Clause|Set]) :-
	test(Set).

clauseset(1,[V1,V2,V3],[[\+V1,V2],[V1,V3],[V2,\+V2],]).