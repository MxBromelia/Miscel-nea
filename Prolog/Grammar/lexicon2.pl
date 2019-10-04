s(s(NP, VP)) --> np(subject, NP), vp(VP).

np(_, np(DET, N))  -->  det(DET),n(N).
np(X, np(PRO)) --> pro(X, PRO).

vp(vp(V, NP))  -->  v(V),np(object, NP). 
vp(vp(V))  -->  v(V). 

det(X, det(Word))  -->  [Word],{lex(Word,det(X))}. 
n(n(Word))  -->  [Word],{lex(Word,n)}. 
v(v(Word))  -->  [Word],{lex(Word,v)}.
pro(X, Y, pro(Word)) --> [Word],{lex(Word,pro(X, Y))}.

lex(the,det(_)). 
lex(a,det(singular)). 
lex(woman,n). 
lex(man,n). 
lex(shoots,v).
lex(he, pro(subject, singular)).
lex(she, pro(subject, singular)).
lex(they, pro(subject, plural)).
lex(him, pro(object, singular)).
lex(her, pro(object, singular)).
lex(them, pro(object, plural)).