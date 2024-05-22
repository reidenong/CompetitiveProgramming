'''
codeforces-1974A Phone Desktop

- screen size is 5x3. we want to fit all the 2x2 squares first, then 1x1 can be filled wherever.

Time/Mem: O(1)
'''
from math import ceil

def solve() :
    x, y = map(int, input().split())

    screens = ceil(y / 2)
    x -= (screens * 15) - (y * 4)

    if x > 0 :
        screens += ceil(x / 15)
    print(screens)

TC = int(input())
for test in range(TC) :
    solve()
  
