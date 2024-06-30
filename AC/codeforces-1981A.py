'''
codeforces-1981A Turtle and Piggy are playing a game

- Essentially we want to find the number between l and r which has the maximum number of divisors, which
  is the same as the number with the maximum number of prime factors.

- Observe that the smallest prime number is 2, so for any number with prime factorization a x b x c x ..., we can always
  find the max number of prime factors by using 2 for all factors. ie. the number is a power of 2.

- Also observe that 2 * l <= r, whjich means that there always exists a power of 2 between l and r.

- So the answer is the largest power of 2 less than or equal to r. This can be found by taking the floor of log2(r).

Time: O(1)
Space: O(1)
'''
from math import log2, floor

def solve() :
    L, R = map(int, input().split())

    print(floor(log2(R)))

tc = int(input())
for _ in range(tc) :
    solve()
