'''
kattis-a1paper

- Greedily make paper with the biggest available, using a smaller one to
  make bigger papers means more tape to connect the smaller ones
- Check usage necessary for each amount of paper. start with needing 2x
  A2 papers, and supplement with A2 papers. if not enough, double the
  number of papers needed as we go to the A+1th grade and check there.
- With a bit of math, we realise that paper sizes decrease with a factor
  of sqroot(2)
- Find tape length by recursively merging paper grades according to the
  usage chart, adding the length of the tape to the total tape count

Time: O(N)
Space: O(N)
'''
from copy import deepcopy
import sys

# Receiving input
N = int(input())
quantities = [int(x) for x in input().split()]

# Test for impossible
merge = deepcopy(quantities)
while len(merge) > 1 :
    qty = merge.pop()
    merge[-1] += qty//2
if merge[0] < 2 :
    print ("impossible")
    sys.exit()

# Quantities Used
# Start with needing 2x A2 papers, which increases to 4x A3 papers and
# so on and so forth
usage = [0 for x in quantities]
needed = 2
for i, quantity in enumerate(quantities) :
    # Can fully use all papers at this quantity
    if quantity >= needed :
        usage[i] = needed
        break

    # Not enough
    else :
        needed -= quantity
        usage[i] = quantity
        needed *= 2

# Function to return amount of tape needed to merge N(papers) into
# N(papers/2) of A-1 grade papers
def mergeTape (A, papers) :
    factor = A - 2
    return pow(2, -0.5 * factor) * pow(2, -3/4) * (papers/2)

# Calculate amount of tape used
tape = 0
while len(usage) > 0 :      # Repeatedly merge smallest papers in usage
    papers = usage.pop()
    if papers > 0 :
        if len(usage) > 0 :
            usage[-1] += papers/2
        tape += mergeTape(len(usage)+2, papers)
print (tape)

