lampada(_).
liga :- retract(lampada(apagada)), assertz(lampada(acesa)).
desliga :- retract(lampada(acesa)), assertz(lampada(apagada)).

memorize(X) :- not(X), assertz(X).

ande(Destination) :- pos(robo, X), X = Destination, format("O robo ja esta no comodo"), !.
ande(Destination) :- pos(robo, X), X \= Destination, retract(pos(robo, X)), assertz(pos(robo, Destination)), format("Saiu da ~w para ~w", [X, Destination]), nl.
pegue(Object) :- pos(Object, Dest), ande(Dest), retract(pos(Object, Dest)), assertz(segura(Object)), format("~w foi pego", Object), nl.
solte(Object) :- pos(robo, Location), segura(Object), retract(segura(Object)), assertz(pos(Object, Location)), format("~w foi soltado", Object), nl.