'''
kattis-natjecanje

- Find all teams with a reserve to lend
- Each team can do one of 3 things: lend left, lend right, do nothing
- Iterate for all combinations

Time: O(RC3)
Space: O(R)
'''
import itertools
from copy import deepcopy

# Receiving input
N, S, R = map(int, input().split())
damaged = [int(x) for x in input().split()]
reserves = [int(x) for x in input().split()]

# Removing teams with reserves who are also damaged
damagedReserves = [kayak for kayak in damaged if kayak in reserves]
for kayak in damagedReserves :
    damaged.remove(kayak)
    reserves.remove(kayak)

# Deciding what each team should do
# Each team with reserve can do one of 3 things -
# lend left, lend right, nothing
minDamaged = 10
combis = list(itertools.combinations_with_replacement('LRN', len(reserves)))
for combi in combis :
    currDamaged = deepcopy(damaged)
    valid = True
    for i in range (len(reserves)) :
        # reserve[i] lend kayak to the left
        if combi[i] == 'L' :
            # Check if valid (ie. there is a team to lend to)
            if reserves[i]-1 in currDamaged :
                currDamaged.remove(reserves[i]-1)
            else :
                valid = False
                break
        
        # reserve[i] lend kayak to the right
        elif combi[i] == 'R' :
            # Check if valid (ie. there is a team to lend to)
            if reserves[i]+1 in currDamaged :
                currDamaged.remove(reserves[i]+1)
            else :
                valid = False

    # Valid sequence of lending, check if there is a new minimum
    if valid :
        if len(currDamaged) < minDamaged :
            minDamaged = len(currDamaged)

# Display output
print (minDamaged)
