'''
kattis-includescoring

 - time waster question, tedious

 - Python sort is stable, so we first sort by multiple keys from the least
   important to the most important

 - Once we have the overall ranking, we assign rankings 1 by 1. We keep track 
   of the people with the same score in a bracket, and then assign the average of al
   the scores in the bracket to all of them when we encounter a new score.

Time: O(N log N) for sorting
Space: O(N) for the array
'''
from math import ceil
from copy import deepcopy

# Ranking function for ease of reference
ranks = [100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
def ranking(x) :
    if (x <= 30) :
        return ranks[x - 1]
    else :
        return 0

# Receiving input
N = int(input())
all = []
for i in range (N) :
    person = [int(x) for x in input().split()] + [i]
        # person = [problems, penalty, time, extra, index ]
    all.append(person)

# Sort by number of problems first
all.sort(key = lambda x : x[2])
all.sort(key = lambda x : x[1])
all.sort(key = lambda x : 9 - x[0])
all2 = deepcopy(all)

# Assign scores in order
currRank = 1        # current rank we are considering
scoring = []        # [score, index]
bracket = []        # bracket of people with same scores, [score, index]
while all :
    # Base case
    if (len(all) == 1) :
        if len(bracket) == 0 :
            scoring.append([ranking(currRank), all[0][4]])
        else :
            bracket.append([ranking(currRank), all[0][4]])    
            totalScore = 0
            for elem in bracket :
                totalScore += elem[0]
            totalScore = ceil(totalScore / len(bracket))
            for elem in bracket :
                scoring.append([totalScore, elem[1]])
        all.pop(0)

    elif (all[0][0:3] != all[1][0:3]) :
        # Handle previous same scores
        if (len(bracket) != 0) :
            bracket.append([ranking(currRank), all[0][4]])    
            all.pop(0)
            currRank += 1

            totalScore = 0
            for elem in bracket :
                totalScore += elem[0]
            totalScore = ceil(totalScore / len(bracket))
            for elem in bracket :
                scoring.append([totalScore, elem[1]])

            bracket = []

        # New independent score
        else :
            scoring.append([ranking(currRank), all[0][4]])
            all.pop(0)
            currRank += 1

    # Same score
    else :
        bracket.append([ranking(currRank), all[0][4]])
        all.pop(0)
        currRank += 1

# Account for extra point, output results
scoring.sort(key = lambda x : x[1])
all2.sort(key = lambda x : x[4])
for i in range (N) :
    print (scoring[i][0] + all2[i][3])
