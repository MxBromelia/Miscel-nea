s_a --> [].
s_a --> l, s_a, r.

l --> [a].
r --> [b].

s --> foo,bar,wiggle.
foo --> [choo]. 
foo --> foo,foo. 
bar --> mar,zar. 
mar --> me,my. 
me --> [i]. 
my --> [am]. 
zar --> blar,car. 
blar --> [a]. 
car --> [train]. 
wiggle --> [toot]. 
wiggle --> wiggle,wiggle.

s_an_b2n --> [].
s_an_b2n --> [a], s_an_b2n, [b], [b].

lan --> [].
lan --> [s, s], lan.

s_x --> [].
s_x --> [a], k, [d].
k --> [b,b,c,c].
k --> [a,b,b], k, [c,c,d].

prop --> cls.
prop --> cls, operator, prop.

cls --> literal.
cls --> [not], literal.

operator --> [and].
operator --> [or].
operator --> [implies].

literal --> [p].
literal --> [q].
literal --> [r].