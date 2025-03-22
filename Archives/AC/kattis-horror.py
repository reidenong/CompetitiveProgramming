'''
kattis-horror

- BFS once from each source node to update the horror index of each node

Time: O(NL)
Mem: O(L) adjacency list
'''
from collections import deque
N, H, L = map(int, input().split())

# Initializing graph
horror = [int(x) for x in input().split()]
adjList = [[] for _ in range(N)]
hi = [9999 for _ in range(N)]
for i in range(L) :
    x, y = map(int, input().split())
    adjList[x].append(y)
    adjList[y].append(x)

# BFS to update movies once from each source
for h in horror :
    hi[h] = 0
    q = deque()
    q.append((h, 0))
    while q :
        idx, val = q.popleft()
        for u in adjList[idx] :
            if hi[u] > val + 1 :
                hi[u] = val + 1
                q.append((u, val + 1))

# Find maximum horror index
curr_max = -1
curr_max_idx = -1
for i, x in enumerate(hi) :
    if x > curr_max :
        curr_max = x
        curr_max_idx = i

print(curr_max_idx)
