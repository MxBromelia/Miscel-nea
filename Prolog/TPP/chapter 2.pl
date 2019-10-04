select(E, [E | R], R).
select(E, [N | L], [ N | R]) :-
	select(E, L, R).