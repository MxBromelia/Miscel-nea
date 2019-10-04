dynamic automata/2.

sigma_asterisk(_,[]).
sigma_asterisk(Sigma,[A|Sterisk]) :-
	sigma_asterisk(Sigma, Sterisk),
	member(A,Sigma).

cartesianProduct(SetA,SetB,SetAxB) :-
	setof((ElementA,ElementB),(member(ElementA,SetA),member(ElementB,SetB)),SetAxB).

nfa_to_dfa(NFA,DFA) :-
	NFA = (Qn,Sigma,Delta_n,Q0n,Fn),
	DFA = (Qd,Sigma,Delta_d,Q0d,Fd),

	setof(Subset, sub_set(Subset,Qn), Qd),
	setof(State,Q^ (member(State,Qd), member(Q,State), member(Q,Fn)), Fd),
	range(Delta_n,Q0n,epsilon,Q0d),
	convert_delta(Delta_n,Qn,Sigma,Delta_d,Qd).

convert_delta(Delta_n,Qn,Sigma,Delta_d,Qd) :-
	setof(Row,I^ (member(I,Qd),
		setof(e(I,J,X),
		SubSet^ (
			member(J,Sigma),
			member(SubSet,Qd),
			range_set(Delta_n,SubSet,epsilon,Range)
		), Row)),
	Delta_d).

range_set(Delta,States,Character,Range) :-
	setof(SubRange,Q^ (member(Q,States), range(Delta,Q,Character,SubRange)), RangeList),
	ord_union(RangeList,Range).

range(Delta,Q,Character,[Q|Range]) :-
	setof(Qi, next_state(Delta,Q,Character,Qi),Range), ! ;
	Range = [].

group_union([],Range,Range).
group_union([List|RangeList],Range0,Range) :-
	ord_union(Range0,List,Range1),
	group_union(RangeList,Range1,Range).

sub_set([],_).
sub_set([S|Ubset],Set) :-
	append(_,[S|Et],Set),
	sub_set(Ubset,Et).

accepts(Automata,String) :-
	Automata = (_,_,Delta,Q0,F),
	last_state(Q0,Delta,String,Last_State),
	member(Last_State,F).

last_state(Last_State,_,[],Last_State).
last_state(Current_State,Delta,String,Last_State) :-
	next_state(Delta,Current_State,epsilon,Next_State),
	last_state(Next_State,Delta,String,Last_State).
last_state(Current_State,Delta,[S|Tring],Last_State) :-
	next_state(Delta,Current_State,S,Next_State),
	last_state(Next_State,Delta,Tring,Last_State).

next_state(Delta,State,Character,Ans) :-
	next_states(Delta,State,Character,Ans0),
	(is_list(Ans0), !, member(Ans,Ans0);
	Ans = Ans0).

next_states(Delta,State,Character,List) :-
	member(Row,Delta),
	member(e(State,Character,List),Row).

automata(c1q1, ([q1,q2,q3,q4],[0,1],Delta,q1,[q4])) :-
	Delta = [[e(q1,0,[q1]), e(q1,1,[q1,q2]), e(q1,epsilon,  [])],
			 [e(q2,0,[q3]), e(q2,1,     []), e(q2,epsilon,[q3])],
			 [e(q3,0,  []), e(q3,1,   [q4]), e(q3,epsilon,[q4])],
			 [e(q4,0,[q4]), e(q4,1,   [q4]), e(q4,epsilon,  [])]].
automata(q4m3n,([qa,qaa],[a,b],Delta,qaa,[qaa])) :-
	Delta = [[e( qa, a,[qaa]), e( qa, b, [qa])],
			 [e(qaa, a, [qa]), e(qaa, b,[qaa])]].
automata(q4m3,([qa,qaa],[a,b],Delta,qaa,[qaa])) :-
	Delta = [[e( qa, a,qaa), e( qa, b, qa)],
			 [e(qaa, a, qa), e(qaa, b,qaa)]].
automata(tst1, ([q1,q2,q3], [0], Delta, q1, [q1])) :-
	Delta = [[e(q1,0,   [q2]), e(q1,epsilon,[])],
			 [e(q2,0,   [q3]), e(q2,epsilon,[])],
			 [e(q3,0,[q1,q2]), e(q3,epsilon,[])]].
automata(epsilon, ([q],[],[[e(q,epsilon,[q])]],q,[q])).
automata(q16iB, ([1,2,3],[a,b],Delta,1,[2])) :-
	Delta = [[e(1, a, [3]),e(1, b,   []), e(1,epsilon,[2])],
			 [e(2, a, [1]),e(2, b,   []), e(2,epsilon, [])],
			 [e(3, a, [2]),e(3, b,[2,3]), e(3,epsilon, [])]].