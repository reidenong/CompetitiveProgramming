'''
kattis-crackingrsa

- generate list of primes with sieve
- bruteforce for the combination of p and q
- bruteforce for the value of d
- Time limit is especially long so bruteforce works here even with 
  168C2 = 14028 permutations of p and q

Time: O(N)
Space: O(1)
'''
import itertools

# Sieve of Eratosthenes
# since smallest prime is 2 and n < 1000, sieve up to 500
N = 1100
primes = []
isPrime = [True for _ in range (N)]
for i in range (2, N) :
    if isPrime[i] :
        primes.append(i)
        tick = i
        while (tick < N) :
            isPrime[tick] = False
            tick += i

# For each testcase
testcases = int(input())
for testcase in range (testcases) :
    N, E = map(int, input().split())

    # Bruteforce combinations of p, q
    combis = list(itertools.combinations(primes, 2))
    for combi in combis :
        if combi[0]*combi[1] == N :
            P, Q = combi[0], combi[1]

    totient = (P-1)*(Q-1)

    for D in range (1, totient + 1) :
        if (D*E)%totient == 1 :
            print (D)
            break

