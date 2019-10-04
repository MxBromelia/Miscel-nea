s --> np(subject, Num), vp(Num).

np(X, Num) --> pro(X, Num).
np(_, Num)  -->  det(Num), noun(Num).

vp(NumSub)  -->  verb(NumSub).
vp(NumSub)  -->  verb(NumSub), np(object, _).

det(Num)  -->  [Word],{lex(Word, det(Num))}.
noun(Num)  -->  [Word], {lex(Word, n(Num))}.
pro(X, Num) --> [Word], {lex(Word, pro(X, Num))}.
verb(Num)  -->  [Word], {lex(Word, v(Num))}.

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

lex(he, pro(subject, singular)).
lex(her, pro(object, singular)).
lex(him, pro(object, singular)).
lex(she, pro(subject, singular)).
lex(them, pro(object, plural)).
lex(they, pro(subject, plural)).