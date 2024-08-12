'''
Reference for Priority Queue DS in python
'''
import heapq

# Init
minheap = []
heapq.heapify(given_list)

# Methods
x = minheap[0]                  # Get smallest item
heapq.heappush(minheap, 5)      # Push to minheap
heapq.heappop(minheap)          # Pop AND RETURNS smallest item on heap

heapq.heappushpop(minheap, 5)   # Push item on heap, then Pop and return smallest item
heapq.heapreplace(minheap, 5)   # Pop and return smallest item, then push new item on heap
