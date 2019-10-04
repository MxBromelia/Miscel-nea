% 2.01 (**) Determine whether a given integer number is prime.
is_prime(X). % foo


% 2.02 (**) Determine the prime factors of a given positive integer.
prime_factors(X,L). % foo


% 2.03 (**) Determine the prime factors of a given positive integer (2).
prime_factors_multi(X,NL). %foo


% 2.04 (*) A list of prime numbers.
prim_list(Lower,Upper,List). % foo


% 2.05 (**) Goldbach's conjecture.
goldbach(N,L). % foo


% 2.06 (**) A list of Goldbach compositions.
goldbach_list(N,NL). % foo

% In most cases, if an even number is written as the sum of two prime numbers, one of them is very small.
% Very rarely, the primes are both bigger than say 50.
% Try to find out how many such cases there are in the range 2..3000.
goldbach_list(N,NL,Limit). % foo


% 2.07 (**) Determine the greatest common divisor of two positive integer numbers.
gcd(Number_1,Number_2,GDC). % foo


% 2.08 (*) Determine whether two positive integer numbers are coprime.
coprime(Number_1,Number_2). % foo

% 2.09 (**) Calculate Euler's totient function phi(m).
% Phi is totient_phi(10)


% 2.10 (**) Calculate Euler's totient function phi(m) (2).


% 2.11 (*) Compare the two methods of calculating Euler's totient function.