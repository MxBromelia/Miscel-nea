% Input						Output
% num_cred([pai,qf,d],X).	30
% courses(alice,X). 		[pai,qf,d]
% pass2(X). 				alice
% fail2(X). 				bob

 num_cred([], 0).
 num_cred([H|T], Sum) :-
 	num_cred(T, Rest),
 	course(H, P, C),
 	Sum is C + Rest.

 courses(X,Y).

 pass2(X).

 fail2(X).

course(pai,inf,10).
course(qf,eco,10).
course(d,law,10).

student(alice,ss).
student(bob,ss).

attend(alice,pai).
attend(alice,qf).
attend(alice,d).
attend(bob,pai).