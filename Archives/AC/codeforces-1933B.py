'''
codeforces-1933B Turtle Math: Fast Three Task

- if the modulo sum is 0, then we are done.

- if the modulo sum is 2, adding 1 to any number will make the modulo sum 0.

- if the modulo sum is 1, we look for any number with mod 1 to remove.
  if such does not exist, we can always add 2 to any number to get 0.
'''
def solve() :
    N = int(input())
    arr = [(int(x) % 3) for x in input().split()]
    diff = sum(arr) % 3

    if diff == 0 :
        print(0)
    
    elif diff == 2 :
        print(1)

    else :
        if arr.count(1) > 0 :
            print(1)
        else :
            print(2)


TC = int(input())
for test in range(TC) :
    solve()
