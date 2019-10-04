:- op(1200,xfx,if).
:- op(1100, fx, :).
:- op(1000,xfy,and).
:- op(500,xf,is_atoy).
:- op(500,xfx,likes).
:- op(500,xfx,plays_with).

: A :- (A if B), (: B).
: A :- A.
A and B :- A, B.

sue likes X if ann likes X.
ann likes X if X is_atoy and ann plays_with X.
doll is_atoy.
snoopy is_atoy.
ann plays_with snoopy.