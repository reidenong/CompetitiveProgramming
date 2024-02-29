'''
codeforces-1937B Binary Path

- we can think of the path as giving as 2 choices of where to go at each step, but the second round is
  offset by 1. so we have 001100 and 110011, then the path can be modeled as
    0 0 1 1 0 0
      1 1 0 0 1 1

- At each step we can see that we can choose from 2 options. Basically at every step, we want to keep adding
  that step to the number of ways UNLESS that step is not possible OR must take.

- At a not possible step, we reset the ways counter as so far is not a valid path.

- At a must take step, we can break as there are no further steps to take

Time: O(N)
Space: O(1)
'''
def solve() :
    N = int(input())
    a = input()
    b = input()
    
    ans = a[0]
    ways = 0
    for i in range(1, N) :
        if a[i] == '0' and b[i - 1] == '1' :
            ways = 0

        if a[i] == b[i - 1] :
            ways += 1

        if a[i] == '1' and b[i - 1] == '0' :
            ways += 1
            ans = a[:i] + b[i - 1:]
            break

        if i == N - 1 :
            ways += 1
            ans = a + b[-1]
        
    print(ans)
    print(ways)



       
    


    
            


    


            


TC = int(input())
for test in range(TC) :
    solve()
