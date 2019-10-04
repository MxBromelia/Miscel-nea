s --> np(subject, _).
s --> np(subject, Num), vp(Num).

np(X, Num) --> pronoun(X, Num).
np(_, Num)  -->  det(Num), noun(Num).
np(_, Num)  -->  det(Num), adjective, noun(Num).

vp(NumSub)  -->  verb(NumSub).
vp(NumSub)  -->  verb(NumSub), np(object, _).

adjective --> [Word], {lex(Word, adjective)}.
det(Num)  -->  [Word],{lex(Word, det(Num))}.
noun(Num)  -->  [Word], {lex(Word, n(Num))}.
preposition --> [Word], {lex(Word, preposition)}.
pronoun(X, Num) --> [Word], {lex(Word, pronoun(X, Num))}.
verb(Num)  -->  [Word], {lex(Word, v(Num))}.

lex(small, adjective).
lex(frightened, adjective).

lex(a, det(singular)).
lex(the, det(_)).

lex(man, n(singular)).
lex(woman, n(singular)).
lex(men, n(plural)).
lex(women, n(plural)).

lex(shoots, v(singular)).
lex(eats, v(singular)).
lex(knows, v(singular)).
lex(eat, v(plural)).
lex(shoot, v(plural)).
lex(know, v(plural)).

lex(he, pronoun(subject, singular)).
lex(her, pronoun(object, singular)).
lex(him, pronoun(object, singular)).
lex(she, pronoun(subject, singular)).
lex(them, pronoun(object, plural)).
lex(they, pronoun(subject, plural)).