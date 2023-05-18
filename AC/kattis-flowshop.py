N, M = map(int, input().split())

stageTime = []
leaveTime = []
for i in range(N):
    line = [int(x) for x in input().split()]
    stageTime += [line]
    leaveTime += [[]]

# Iterate down each column to see the time they leave.
# Once first column is processed, move to next column, where you see if 
# swather is available or not
currTime = 0
for i in range(M):      # Iterate column (swather i)
    if i != 0:
        currTime = leaveTime[0][-1]

    for j in range(N):  # Iterate row (product j)
        if i != 0 and j != 0:
            currTime = max(leaveTime[j][-1], currTime)

        # Update currTime
        leaveTime[j] += [currTime + stageTime[j][i]]
        currTime = leaveTime[j][-1]


ansString = ""
for i in range(N):
    ansString += str(leaveTime[i][-1]) + " "
print(ansString[:-1])






    
