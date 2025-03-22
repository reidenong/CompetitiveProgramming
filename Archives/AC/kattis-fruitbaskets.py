'''
kattis-fruitbaskets

- easier to recursive backtrack for the complement of the set of fruit
  baskets weighing more than 200g, given each fruit is between 50-1000g
  meaning that at most the depth of each small fruit basket is 3

Time: O(2^number_of_sub200_weights)
Space: O(N)
'''
# Receiving input
N = int(input())
weights = [int(x) for x in input().split()]

# Calculating weight of all possible combinations
totalMass = 0
for weight in weights :
    # In the set of all possible combinations, every object appears
    # exactly 2^(N-1) times (because 2^(N-1) ways to choose all other objects)
    totalMass += weight*pow(2, N-1)

# Getting weight of small items
smalls = []
for weight in weights :
    if weight < 200 :
        smalls.append(weight)
smallN = len(smalls)

# Recursive backtracking
def backtrack (idx, mass) :
    
    # End of backtrack depth reached
    if idx == smallN :
        return 
    
    # Don't choose small fruit [idx]
    backtrack(idx + 1, mass)

    # Choose small fruit [idx]
    mass += smalls[idx]
    if mass < 200 :     # Check if mass passes test
        global totalSmall
        totalSmall += mass
        backtrack(idx + 1, mass)
    else :
        return

# Backtrack and display answer
totalSmall = 0
backtrack(0, 0)
print (totalMass - totalSmall)


