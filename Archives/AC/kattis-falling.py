'''
kattis-falling

- abridged question: solve a^2 - b^2 = D for real integers a, b

                D = (a-b)(a+b) --(Eqn 1)

- too slow to bruteforce for all combinations of a,b in space [1,200k]
- faster to check all factors of D for one that fulfils (Eqn 1)

- do prime factorization for D, then check all factors for the above 
  formula
- for D <= 200000, the value of D with the most factors is
  D = 166320 with 160 factors. so worst case is O(80 pairs) which is still
  relatively very fast
- bottleneck is probably the prime factorization

Time: O(D^0.5)
Space: O(160 numbers) = O(1)
'''
from math import ceil
import sys
D = int(input())

# Prime factorization for pairs of factors of D.
factorPairs = []
for i in range (1, ceil(D**0.5)+1) :
    if D % i == 0 :
        factorPairs += [[i, int(D/i)]]

# Check if any pairs of factors satisfy (a+b)(a-b)
for pair in factorPairs :
    # Derive A and B
    twoA = pair[0] + pair[1]
    if twoA%2 == 0 and twoA != 0 :
        A = twoA/2
        B = max(pair) - A

        if A == int(A) and B == int(B) :
            A, B = int(A), int(B)
            if A > B :
                print (B, A)
            else :
                print (A, B)
            sys.exit()

# No possible alternative
print ("impossible")
