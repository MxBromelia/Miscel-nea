s --> np(sub), vp.

np(_)  -->  det,n.
np(X) --> pro(X).

vp  -->  v,np(obj). 
vp  -->  v. 

det  -->  [Word],{lex(Word,det)}. 
n  -->  [Word],{lex(Word,n)}. 
v  -->  [Word],{lex(Word,v)}.
pro(X) --> [Word],{lex(Word,pro(X))}.

lex(the,det). 
lex(a,det). 
lex(woman,n). 
lex(man,n). 
lex(shoots,v).
lex(he, pro(sub)).
lex(she, pro(sub)).
lex(him, pro(obj)).
lex(her, pro(obj)).