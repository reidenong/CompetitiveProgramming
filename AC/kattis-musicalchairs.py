'''
kattis-musicalchairs

- irritating to get the indexes right
- use modulo to determine the person to choose and then remove the 
  person from the group

Time: O(N)
Space: O(N)
'''
# Receiving input
N = int(input())
counts = [int(x) for x in input().split()]
people = [x for x in range (N)]

# Elimination
starter = 0
while len(people) > 1 :
    # Choosing next out
    chosenIdx = (people.index(starter) + counts[starter] - 1) % len(people)
    chosen = people[chosenIdx]

    # Choosing next starter
    if chosen == people[-1] :
        starter = people[0]
    else :
        starter = people[chosenIdx + 1]

    # Removing chosen one from pool
    people.remove(chosen)

print (people[0] + 1) # 1-indexed
