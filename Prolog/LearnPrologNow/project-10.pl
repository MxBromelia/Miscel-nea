%Project 10.1
nu(1,A,B) :- \+A=B.

nu(2,A,B) :- A = B, fail.

nu(3,A,A) :- !,fail.
nu(3,_,_).