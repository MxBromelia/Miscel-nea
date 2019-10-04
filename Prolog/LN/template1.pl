:- use_module(read_sentence, [read_sentence/1]).

sent(Nomes) --> name_rec(Nomes).

name_rec(Nomes) --> rec(_,Num), name(Num, Nomes).

rec(P,N) --> pro(pes,P,N), verb(ser,P,N).

pro(pes, 1, s) --> [eu].
pro(pes, 2, s) --> [tu].
pro(pes, 3, s) --> [ele].
pro(pes, 3, s) --> [ela].
pro(pes, 3, s) --> [voce].
pro(pes, 1, p) --> [nos].
pro(pes, 2, p) --> [vos].
pro(pes, 3, p) --> [eles].
pro(pes, 3, p) --> [elas].
pro(pes, 3, p) --> [voces].
pro(pos, 1, s) --> [meu].
pro(pos, 2, s) --> [teu].
pro(pos, 3, s) --> [seu].
pro(pos, 1, p) --> [nosso].
pro(pos, 2, p) --> [vosso].
pro(pos, 3, p) --> [seus].

verb(ser,1,s) --> [sou].
verb(ser,2,s) --> [es].
verb(ser,3,s) --> [e].
verb(ser,1,p) --> [somos].
verb(ser,2,p) --> [sois].
verb(ser,3,p) --> [sao].

name(s, [Nomes]) --> [Nomes].
name(p, [Nome|Nomes]) --> [Nome,','], name(p, Nomes).
name(p, [Nome|Nomes]) --> [Nome, e], name(s, Nomes).

template_ia :-
	write('- Oi, qual o seu nome?'), nl,
	read_sentence(L),
	sent(Name, L, []),
	(
		(Name = [_|[]],	
		format(" - Seu nome e ~w.", Name))
	;
		(Name = [_|[_|_]],
		format(" - Seus nomes sao ", []),
		write_names(Name))
	).

write_names([X,Y|[]]) :- format("~w e ~w", [X, Y]), !.
write_names([X|L]) :-
	format("~w, ", X),
	write_names(L).