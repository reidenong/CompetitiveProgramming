# kattis-blackfriday
from copy import deepcopy

N = int(input())
scores = [int(x) for x in input().split()]
scoresCopy = deepcopy(scores)

outcome = 0
while len(scores) > 0 :
    currIdx = scores[0]
    scores.remove(currIdx)

    if not currIdx in scores :
        if currIdx > outcome :
            outcome = currIdx
    
    while currIdx in scores :
        scores.remove(currIdx)

if outcome == 0 :
    print ("none")
else:
    print (scoresCopy.index(outcome) + 1)
