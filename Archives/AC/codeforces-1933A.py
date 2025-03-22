'''
codeforces-1933A Turtle Puzzle: Rearrange and Negate

- move all -ves to the left and make them +ve, ie. just sum all the absolute values
'''
def solve() :
    N = int(input())
    arr = [abs(int(x)) for x in input().split()]
    print(sum(arr))

TC = int(input())
for test in range(TC) :
    solve()
