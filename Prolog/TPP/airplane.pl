%Chapter 5 - Airport Control Program Example
airport_control :-
	repeat,
		receive_message(M),
		process_message(M),
	terminate(M).

receive_message(M) :- read_sentence(M), nl.

process_message(Message) :-
	check_message(Message, Response),
	respond_message(Response).

check_message(Message,Response) :-
	request_service(Message,Airplane,Response),!,
	add_to_queue(Airplane).
check_message([Flight|Rest],_,Response),!,
	change_runway(busy:Flight,free:_).
check_message(_,Response) :- error_message(Response).

request_service([Flight,request,Service],Airplane,
	[Flight,Service,'request received. Please Wait!']) :-
	valid(Flight,Service,Airplane).

complete_service([Flight,Service,completed],_,
	[Flight,Service,'completion recorded']) :-
	valid(Flight, Service, Airplane).

error_message(['Invalid message! Use following format:',nl,
	'FlightNumber request <landing/taking-off>'nl,
	'FlightNumber <landing/take-off> completed',nl]).

valid(Flight,landing,landing(Flight)).
valid(Flight,'taking-off',takingoff(Flight)).

add_to_queue(Airplane) :- assertz(Airplane).

change_runway(A, B) :-
	retract(runway(A)),!,asserta(runway(B)).
change_runway(_,_) :-
	respond_message(['Invalid fligh. Try Again']),
	fail.

process_runway :-
	runway(free:_),
	provide_service(Flight),
	change_runway(_,busy:Flight).
process_runway.

provide_service(Flight) :-
	retract(landing(Flight)),!,
	respond_message([Flight, 'may proceed landing now']).
provide_service(Flight) :-
	retract(takingoff(Flight)),!,
	respond_message([Flight,'may proceed taking off now.']).
provide_service(_) :-
	respond_message('> Report: No airplane in sight.']),
	nl,fail.

respond_message([]) :- nl, nl.
respond_message([H|T]) :-
	(H = nl, nl, !; write(H),write(' ')),
	respond_message(T).

runway(free:_).
terminate([zzzz]).

read_sentence(L) :- read_sent(32,L).