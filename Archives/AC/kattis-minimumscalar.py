'''
kattis-minimumscalar

- we want to pair the smallest of set X with the largest of set Y
- Achieved by sorting x ascending and y descending, so we can use O(1) pop 
  operation though this is probably unnecessary for such small input numbers

Time: O(N)
Space: O(N)
'''
# For each testcase
TCs = int(input())
for TC in range (TCs) :
    # Receiving, sorting input
    N = int(input())
    X = [int(x) for x in input().split()]
    Y = [int(x) for x in input().split()]

    # Sorting
    X.sort()
    Y.sort(reverse=True)

    # Multiplying smallest and largest of each set
    scalar = 0
    while len(X) > 0 :
        scalar += X.pop() * Y.pop()
    
    print ("Case #" + str(TC+1) + ":", scalar)
