:- module(read_sentence, [read_sentence/1]).
% ASCII codes referecence
%
% 008: backspace (\b)
% 013: carriage return (\r)
% 032: space
% 039: simple qoute (')
% 044: comma (,)
% 045: hifen (-)
% 046: period (.)
% 063: interrogation (?)
% 048-057: number digits(0-9)
% 065-090: alphabet in capital letters (A-Z)
% 097-122: alphabet letters (a-z)

read_sentence(L) :- read_sent(32,L).

read_sent(C,L) :- end_sent(C),!,L = [].
read_sent(C,[W|L]) :-
	read_word(W,C1),read_sent(C1,L).

read_word(W,C1) :-
	read_first_char(S,C),
	read_word_chars(S,C,[],L,C1),
	reverse(L,L1),name(W,L1).

read_first_char(S,C) :-
	get_charcode(S),start_word(S,C),!;
	read_first_char(S,C).

read_word_chars(S,C,L,L,C1) :- end_word(S,C,C1),!.
read_word_chars(S,8,[C|L],L1,C1) :- !,
	put(32),put(8),get_charcode(C2),
	read_word_chars(S,C2,L,L1,C1).
read_word_chars(S,C,L,L1,C1) :-
	legal_char(S,C),get_charcode(C2),
	read_word_chars(S,C2,[C|L],L1,C1).

get_charcode(C) :- get0(C), (C=13,!,nl;true).
start_word(C,C) :- valid_char(C),!.
start_word(39,C) :- get_charcode(C).
end_word(39,39,C) :- get_charcode(C).
end_word(S,C,C) :- S \= 39, C \= 8, not(valid_char(C)). % Neither quote(') nor backspace, and a invalid char
end_sent(C) :- (C = 46;C = 63). % C = '.' or '?'

legal_char(39,_) :- !.
legal_char(_,C) :- valid_char(C).
valid_char(C) :- 
	C = 44; % comma
	C = 45; % hifen
	48 =< C, C =< 57; % 0-9
	65 =< C, C =< 90; % A-Z
	97 =< C, C =< 122. % a-z