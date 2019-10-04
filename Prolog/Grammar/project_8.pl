s(s(NP,VP))  -->  np(subject, NP),vp(VP). 
 
np(_, np(DET,N))  -->  det(DET),n(N).
np(X, np(PRO)) --> pro(X, PRO).
 
vp(vp(V,NP))  -->  v(V),np(object, NP). 
vp(vp(V))        -->  v(V). 
 
det(det(the))  -->  [the]. 
det(det(a))      -->  [a]. 
 
n(n(woman))  -->  [woman]. 
n(n(man))      -->  [man].

pro(subject, pro(he)) --> [he].
pro(subject, pro(she)) --> [she].
pro(object, pro(him)) --> [him].
pro(object, pro(her)) --> [her].
 
v(v(shoots))  -->  [shoots].