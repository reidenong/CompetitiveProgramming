'''
kattis-canvas

- key observation is that the canvases can be organised as one wishes, and that
  every action is a partitioning action across two elements. In the end, every
  element will be partitioned at least once
- the trick is to do it bottom up, which is to do mergers instead of partitions.
  by merging every 2 of the smallest available canvases and adding it back, we are
  eventually able to merge all canvases in an optimal manner

Time: O(N log N) with log N priority queue
Space: O(N)
'''
import heapq

# For each testcase
TCs = int(input())
for testcase in range (TCs) :

    # Receiving input
    N = int(input())
    canvases = [int(x) for x in input().split()]

    # Place canvases into priority queue
    heapq.heapify(canvases)

    # Merge smallest two canvases, record painting
    paint = 0
    while len(canvases) > 1 :
        merge = heapq.heappop(canvases) + heapq.heappop(canvases)
        paint += merge
        heapq.heappush(canvases, merge)
    
    print (paint)
