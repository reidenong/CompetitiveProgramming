'''
codeforces-1937A Shuffle Party

- biggest divisor of 1 is 2, then after that is 4 and so on.

- We realise the last step that 1 will go is to 2**x, where x is the largest power of 2 that is less than or equal to N
'''
def solve() :
    N = int(input())
    
    a = 1
    while (2*a) <= N :
        a *= 2

    print(a)

TC = int(input())
for test in range(TC) :
    solve()
