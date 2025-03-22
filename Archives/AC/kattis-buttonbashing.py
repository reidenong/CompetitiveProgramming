'''
kattis-buttonbashing

- BFS / Similar to bottom up DP

- Basically we want to keep trying all new possibilities. With BFS, as time increases the number of 
  presses are increasing, so we only want to update the memo if we have not visiited it already, as the earlier
  visit is guaranteed to be a shorter trip

- Important to remember that if we exceeed 3600, we want to go to 3600. But we only need to
  append 3600 to the queue once, as we only need to find the shortest path from 3600 once.

Time: O(3600*N) = O(N)
Mem: O(3600) = O(1)
'''
from collections import deque
TC = int(input())
for tc in range(TC) :
    N, T = map(int, input().split())
    buttons = [int(x) for x in input().split()]

    # Initializing DSes
    memo = [-1 for _ in range (3601)]
    memo[0] = 0
    q = deque()
    q.append(0)

    # BFS
    while len(q) > 0 :
        top = q.popleft()

        for b in buttons :
            if top + b >= 3600 :
                # First time we encounter 3600 or >3600
                if memo[3600] == -1 :           
                    memo[3600] = memo[top] + 1
                    q.append(3600)
                continue
                
            # Try this combination if it is new and valid (time > 0)
            if top + b > 0 and memo[top + b] == -1 :
                memo[top + b] = memo[top] + 1
                q.append(top + b)

    # Finding memo T or the nearest memo to T
    extra = 0
    while memo[T + extra] == -1 :
        extra += 1
    print(memo[T + extra], extra)
