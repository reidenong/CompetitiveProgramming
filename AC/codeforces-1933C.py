'''
codeforces-1933C Turtle Fingers: Count the value of k

- Bruteforce will work.

- Best to settle cases where either A or B is 1 as we will TLE easily: even if A is 2, log base 2 of INT_MAX is 30, 
  whereas if A is 1, we may be iterating 10^5 times.

- Put all k in a set to ensure no duplicates

Time: O(log_A(L) * log_B(L)) 
Memory: O(log_A(L) * log_B(L))
'''
from math import pow

def solve() :
    A, B, L = map(int, input().split())
    ways = set()

    counter = 0
    
    # A == B == 1
    if A == 1 and B == 1 :
        print(1)
        return
    
    # A == 1 or A == B
    if A == 1 or A == B:
        for i in range(100) :
            x = pow(B, i)
            if L >= x and L % x == 0 :
                ways.add(L // x)
            if x > L :
                x = 0
                break
        print(len(ways))
        return
    
    # B == 1
    if B == 1 :
        for i in range(100) :
            x = pow(A, i)
            if L >= x and L % x == 0 :
                ways.add(L // x)
            if x > L :
                x = 0
                break
        print(len(ways))
        return
    
    # A != B 
    for i in range(100) :
        for j in range(100) :
            x = pow(A, i) * pow(B, j) 
            if L >= x and L % x == 0 :
                ways.add(L // x)
            if x > L :
                x = 0
                break
        if x > L :
            break
    
    print(len(ways))

TC = int(input())
for test in range(TC) :
    solve()
