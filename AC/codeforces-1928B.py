'''
CF1928B - Equalize

 - Firstly, we remove all duplicates as these elements are useless, since we every element
   in a permutation is unique. We also sort the array

 - Generally, we maintain a sliding window with indexes such that the difference between
   the largest and smallest element is at most N. Since every element in the array is
   unique, each element in this window can have some sum from a permutation to a certain
   number.

 - We increase the right index, and if the difference between the largest and smallest 
   elements is too big, we pop the left index. We keep track of the maximum window size
'''
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]
 
    arr = list(set(arr))    # Remove duplicates
    arr.sort()              # Sort array
    
    # Simulate sliding window
    ans = 1
    smallest_idx = 0
    for i in range(1, len(arr)) :
 
        while smallest_idx < i and (arr[i] - arr[smallest_idx]) >= N :
            smallest_idx += 1
            
        ans = max(ans, i - smallest_idx + 1)
    
    print(ans)

TC = int(input())
for test in range(TC) :
    solve()
