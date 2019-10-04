sum_nat(1, 1).

sum_nat(S, N) :- N > 1,
                 Nm1 is N-1,
                 sum_nat(S0, Nm1),
                 S is S0+N.