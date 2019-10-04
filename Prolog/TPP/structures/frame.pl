:- op(500,xfx,has).
:- op(500,xfx,isa).

%EVENT				FRAME
event has			[place: P, day: D, time: T].
disaster_event has 	[killed: K, injuried: I, damage: D].
political_event has	[who: W, what: H].
sport_event has		[sport: S, winner: W, score: C].
earthquake has		[magnitude: M].

disaster_event isa event.
political_event isa event.
sport_event isa event.
earthquake isa disaster_event.

create_frame(Event,Frame) :-
	bagof(Slot,collect_slot(Event,Slot),Frame),
	fillup(Frame).

collect_slot(Event,Slot) :-
	Event isa Event1, collect_slot(Event1,Slot).
collect_slot(Event,Slot) :-
	Event has Frame, member(Slot,Frame).

fillup([]) :- nl.
fillup([Slot:Filler|Rest]) :-
	write(Slot), write(' : '),nl,
	read(Filler),
	fillup(Rest).

news(earthquake,[place:P, day:D, time:T, killed:K, injuried:I, damage:Da, magnitude: M],
	['An','earthquake',ocurred,in,P,D,at,T,measured,at,M,on,the,'Richter',scale,'.',
		'There',were,K,killed,',',I,injuried,and,damage,estimated,at,'$',Da,'.']).

print_news([]):-nl.
print_news([W|Rest]) :-
	(var(W), write('unknown ') ;
		nonvar(W), (W = nl, !, nl; write(W), write(' '))),
	print_news(Rest).

print_news_format([W|Rest],Margin) :-
	print_news_format([W|Rest],0,Margin).

print_news_format([],_,_) :- nl,!.
print_news_format([W|Rest],Count,Margin) :-
	(
		nonvar(W), !,Word = W
	;
		Word = unknown
	),
	atom_length(Word,N),
	Total is N+Count+1,
	(
		Total =< Margin, !, write(Word), write(' '), print_news_format(Rest,Total,Margin)
	;
		nl, write(Word),write(' '), print_news_format(Rest,N,Margin)
	).

frame([place:newcastle, day:today, time:'5-am', killed:8, injuried:_, damage:'2-million', magnitude:6.5]).

test(L) :-
	frame(X),
	news(earthquake,X,N),
	print_news_format(N,L).