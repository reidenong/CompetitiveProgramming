'''
codeforces-1978A Alice and Books

- Notice a few things. The last book will always be considered no matter what as
  it has the highest number by default.

- Any other book can be considered as long as it is the last book in its stack.

- This means that we just pick the last book and the book with the highest number 
  of pages.

Time: O(N)
Mem: O(1)
'''
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]

    max_val = -1
    for i in range(N - 1) :
        max_val = max(arr[i] + arr[N - 1], max_val)

    print(max_val)

tc = int(input())
for _ in range(tc) :
    solve()
