% automata(Label,Automata), Automata = (Q,Sigma,Delta,Q0,F).
dynamic automata/2.

unionSet(SetA,SetB,UnionSet) :-
	setof(Element,(member(Element,SetA);member(Element,SetB)),UnionSet).
interSet(SetA,SetB,InterSet) :-
	setof(Element,(member(Element,SetA),member(Element,SetB)),InterSet).
minusSet(SetA,SetB,MinusSet) :-
	setof(Element,(member(Element,SetA),\+ member(Element,SetB)),MinusSet).
cartesianProduct(SetA,SetB,SetAxB) :-
	setof((ElementA,ElementB),(member(ElementA,SetA),member(ElementB,SetB)),SetAxB).

union_dfa(Automata1,Automata2,Automata) :-
	Automata1 = (Q1,Sigma1,Delta1,Q01,F1),
	Automata2 = (Q2,Sigma2,Delta2,Q02,F2),
	Automata  = ( Q, Sigma, Delta, Q0, F),

	cartesianProduct(Q1,Q2,Q),
	unionSet(Sigma1,Sigma2,Sigma),
	union_delta(Q,Sigma,Delta1,Delta2,Delta),
	Q0 = (Q01,Q02),
	setof((ElementA,ElementB), (member(ElementA,Q1),member(ElementB,Q2),(member(ElementA,F1);member(ElementB,F2))), F).

intersec_dfa(Automata1,Automata2,Automata) :-
	Automata1 = (Q1,Sigma1,Delta1,Q01,F1),
	Automata2 = (Q2,Sigma2,Delta2,Q02,F2),
	Automata  = ( Q, Sigma, Delta, Q0, F),

	cartesianProduct(Q1,Q2,Q),
	unionSet(Sigma1,Sigma2,Sigma),
	union_delta(Q,Sigma,Delta1,Delta2,Delta),
	Q0 = (Q01,Q02),
	cartesianProduct(F1,F2,F).

union_delta(Q,Sigma,Delta1,Delta2,Delta) :-
	setof(Row, I^ (member(I,Q),
		setof(e(I,J,(X,Y)),
		IA^ IB^ (
			member(J,Sigma),
			I = (IA,IB),
			next_state(Delta1,IA,J,X),
			next_state(Delta2,IB,J,Y)),
		Row)), Delta).

valid_dfa(Automata) :-
	Automata = (Q,Sigma,Delta,Q0,F),
	 %q0 é um estado do automato
	member(Q0,Q),
	 %F é um subconjunto de estados do automato
	setof(State,(member(State,Q), member(State,F)), F),
	%Delta é injetiva
	setof((State,Char), NXT^ next_state(Delta,State,Char,NXT), L),
	setof((State,Char), (member(State,Q), member(Char,Sigma)), L).

accepts(Automata,String) :-
	Automata = (_,_,Delta,Q0,F),
	last_state(Q0,Delta,String,Last_State),!,
	member(Last_State,F).

last_state(Last_State,_,[],Last_State).
last_state(Current_State,Delta,[S|Tring],Last_State) :-
	next_state(Delta,Current_State,S,Next_State),
	last_state(Next_State,Delta,Tring,Last_State).

next_state(A,I,J,X) :-
	member(Row,A), member(e(I,J,X),Row).

automata(q4m1,([q1,qa,qaa,qaaa],[a,b],Delta,q1,[qaaa])) :-
	Delta = [[e(  q1, a,  qa),e(  q1, b,  q1)],
			 [e(  qa, a, qaa),e(  qa, b  ,qa)],
			 [e( qaa, a,qaaa),e( qaa, b, qaa)],
			 [e(qaaa, a,qaaa),e(qaaa, b,qaaa)]].	
automata(q4m2,([q2,qb,qbb],[a,b],Delta,q2,[qbb])) :-
	Delta = [[e( q2, a, q2), e( q2, b, qb)],
			 [e( qb, a, qb), e( qb, b,qbb)],
			 [e(qbb, a,qbb), e(qbb, b,qbb)]].
automata(q4m3,([qa,qaa],[a,b],Delta,qaa,[qaa])) :-
	Delta = [[e( qa, a,qaa), e( qa, b, qa)],
			 [e(qaa, a, qa), e(qaa, b,qaa)]].
automata(q4m4, ([q4,qb,qbb,qbbb], [a,b], Delta, q4, [qb,qbb])) :-
	Delta = [[e(  q4, a,  q4), e(  q4, b,  qb)],
			 [e(  qb, a,  qb), e(  qb, b, qbb)],
			 [e( qbb, a, qbb), e( qbb, b,qbbb)],
			 [e(qbbb, a,qbbb), e(qbbb, b,qbbb)]].
automata(q4m5, ([q5,qa,qab],[a,b],Delta,q5,[qab])):-
	Delta = [[e( q5, a,qa), e( q5 ,b, q5)],
			 [e( qa, a,qa), e( qa, b,qab)],
			 [e(qab, a,qa), e(qab, b,qab)]].