'''
kattis-icpcteamselection

- We want to find N groupings of 3N items where we maximise median
- We can achieve this by greedily forming teams with the top 2 and bottom most
  score, such that the median is maximised at the 2nd item.

Time: O(N)
Space: O(N)
'''
# For each testcase
TCs = int(input())
for TC in range (TCs) :
    # Receiving, sorting input
    N = int(input())
    scores = [int(x) for x in input().split()]
    scores.sort()

    # Greedy team selection
    medians = []
    for i in range (N) :
        scores.pop()                    # Throw away largest item
        medians.append(scores.pop())    # Keep median 
        scores = scores[1:]             # Throw away smallest score

    print (sum(medians))
        
