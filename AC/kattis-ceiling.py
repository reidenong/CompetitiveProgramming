'''
kattis-ceiling

- binary trees can be represented in linear form in an array, such that
  for a item with root at [pos], if it is smaller it takes position 
  [2*(pos) + 1] and if it is larger it takes position [2*(pos+1)]
- array might need up to 2^20 for 20 insertions if all are in a single
  direction, use hashmap for storing max 20 insertions
- Trees with the same structure will store items at the same indexes hence
  to get overall structure we just need to store unique list of indexes
  for each tree
- remember to sort indexes as python set no autosort

Time: O(N)
Space: O(N)
'''
shapes = set()

# Receiving input
N, K = map(int, input().split())

# Adding to the set of unique shapes
for i in range (N) :
    # Receiving ceiling input
    ceiling = [int(x) for x in input().split()]

    # Create binary tree
    tree = {}
    indexes = set()
    for node in ceiling :
        pos = 0
        while pos in tree :
            if node > tree[pos] :
                pos = 2*(pos + 1)
            else :
                pos = 2*pos + 1
        tree[pos] = node
        indexes.add(pos)
    
    # Add unique binary tree positions
    shapes.add(tuple(sorted(indexes)))

print (len(shapes))

