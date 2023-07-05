'''
O(N log K) Longest Increasing Subsequence (LIS)

- Uses greedy and divide & conquer to give LIS in O(N log k) 
  time instead of usual O(N^2) Time
  
- With a linear pass through the given arr for elem, it creates a empty list 'seq'
  and chooses between 1 of 2 options: 
      (1) If seq is empty or elem is new largest element, it appends elem to the end
          of seq
      (2) Else it finds the lower bound of elem in seq and replaces that element

- This greedily chooses following "smaller" elements in the LIS to replace current 
  elements in the constructed LIS, thus increasing the ability to create a longer
  LIS later on

- It also tracks the predecessors of each element, thus being able to reconstruct the
  lexographically smallest LIS by just seeing the last element of the LIS and backtracking
  its predecessors

Time: O(N log K) where K is the length of LIS
Space: O(N)
'''
def LIS (arr) :
    inLIS = set()
    seq = []
    predecessors = {}
    for i, elem in enumerate (arr) :
        if i == 0 :
            seq.append(elem)
            predecessors[elem] = -1
            continue
        
        pos = bisect_left(seq, elem)
        if pos == len(seq) :
            seq.append(elem)
            predecessors[elem] = seq[-2]
        else :
            seq[pos] = elem
            if pos == 0 :
                predecessors[elem] = -1
            else :
                predecessors[elem] = seq[pos-1]
    
    # Reconstruct LIS from the largest element of LIS
    curr = seq[-1]
    while curr != -1 :
        inLIS.add(curr)
        curr = predecessors[curr]

    return len(seq), sorted(inLIS)
