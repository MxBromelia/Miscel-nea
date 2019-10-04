select_acc(H, [H|T], T).
select_acc(X, [_|T], T1) :-
	select_acc(X, T, T1).