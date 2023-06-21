'''
kattis-eenymeeny

- irritating to get the indexes right
- use modulo to determine the person to choose and then remove the 
  person from the group

Time: O(N)
Space: O(N)
'''
# Receiving input
rhyme = len(input().split())
N = int(input())
people = []
for i in range (N) :
    people += [input()]

# Picking people
teams = [[],[]]
currPick = 0
nextPerson = people[0]
while len(people) > 0 :
    # Finding the next chosen one
    chosen = people[(people.index(nextPerson) + rhyme%len(people)-1)%len(people)]
    teams[currPick] += [chosen]

    # Deciding where the next round of choosing starts
    if chosen == people[-1] :
        nextPerson = people[0]
    else :
        nextPerson = people[(people.index(nextPerson) + rhyme%len(people)-1)%len(people) + 1 ]
    
    # Removing the chosen one from people
    people.remove(chosen)

    # Swapping where the person is going to
    if currPick == 0 :
        currPick = 1
    else :
        currPick = 0

# Displaying teams
for team in teams :
    print (len(team))
    for person in team :
        print (person)

