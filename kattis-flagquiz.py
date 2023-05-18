'''
kattis-flagquiz

-reading comprehension important wrt minimum maximum number of changes

'''
import sys

# Returns number of changes needed between 2 strings
def numOfChanges(listA, listB):
    changes = 0
    for (a, b) in zip(listA, listB):
        if a != b:
            changes += 1
    return changes

# Receiving input
question = input()
answers = []
N = int(input())
for i in range(N):
    line = input().split(', ')
    answers += [line]
numOfTerms = len(answers[0])

# Initialize Answer Arrays
currMin = 5001
finalAnswers = []

# Calculate frequency for every ith term, record most likely outcome
for i in range(N):
    maxChanges = 0

    for j in range(N):
        maxChanges = max(maxChanges, numOfChanges(answers[i], answers[j]))

    #print(answers[i], totalChanges)
    # Case 1: New Minimum
    if maxChanges < currMin:
        finalAnswers = [answers[i]]
        currMin = maxChanges

    # Case 2: Second Minimum
    elif maxChanges == currMin:
        finalAnswers += [answers[i]]

# Output Answers
noDup = []
for ans in finalAnswers:
    outputLine = ""
    for word in ans:
        outputLine += word + ", "
    if outputLine[:-2] not in noDup:
        noDup += [outputLine[:-2]]

for line in noDup:
    print(line)
