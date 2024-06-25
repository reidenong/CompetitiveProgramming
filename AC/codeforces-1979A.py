'''
codeforces-1979A Guess the Maximum

- The shortest of all possible subsequences would be all subsequences of length 2

- for all length-2 contig. subsequences make sure we have a answer value smaller than the max of both numbers

Time: O(N)
Mem: O(N)
'''
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]
 
    curr_max = int(10**9)
    for i in range(N - 1) :
        curr_max = min(curr_max, max(arr[i], arr[i+1]) - 1)
    
    print(curr_max)
 
TC = int(input())
for _ in range(TC) :
    solve()
