:-dynamic (table/3).

make_array2(Array) :-
	row_indices(IList),
	col_indices(JList),
	setof(Row, I^(member(I,IList),
		setof(e(I,J,_),member(J,JList),Row)),
		Array).

make_table(Table) :-
	setof(Row,
		H^ setof(e(I,J,X),(table(H,J,X),I=H),Row),
		Table).

transpose(N,Table,Table1) :-
	setof(Col,(M,X,Row)^
		^(nth_member(M,X,Row),
		(M > N, !, fail;
		setof(X,Row^ member(Row,Table),Col))),
	Table1).

nth_member(1,X,[X|_]) :- !.
nth_member(N,X,[_|T]) :-
	nth_member(M,X,T), N is M+1.

row_indices([1,2,3,4,5,6]).
col_indices([1,2,3,4,5,6]).