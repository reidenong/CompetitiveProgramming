'''
kattis-rings2

- Iterate through all Ts, solve all 1s, then 2s, until all Ts are resolved

'''

# Function to print treemap when <10 rings
def printTreeMap_S():
    global treeMap
    for i in range(len(treeMap)):
        outputLine = ""
        for j in range(len(treeMap[0])):
            outputLine += "." + str(treeMap[i][j])
        print(outputLine)

# Function to print treeMap when >=10 rings
def printTreeMap_B():
    global treeMap
    for i in range(len(treeMap)):
        outputLine = ""
        for j in range(len(treeMap[0])):
            if len(str(treeMap[i][j])) > 1:
                outputLine += "." + str(treeMap[i][j])
            else:
                outputLine += ".." + str(treeMap[i][j])
        print(outputLine)

# Receiving input
row, col = map(int, input().split())
treeMap = []
solvedTreePos = []
treePos = []
for i in range(row):
    line = [x for x in input()]
    for j, symbol in enumerate(line):
        if symbol == "T":
            treePos += [[i,j]]
    treeMap += [line]

# Solve for 1s
#print("total Trees", len(treePos))
for pos in treePos:
    row, col = pos

    # Any edge T has to be a 1 by definition
    if (row == 0 or 
        col == 0 or 
        row == len(treeMap)-1 or 
        col == len(treeMap[0])-1):
        solvedTreePos += [pos]
        treeMap[row][col] = 1
    
    # Any T with a '.' neighbour is a 1
    elif (treeMap[row-1][col] == '.' or treeMap[row+1][col] == '.' or 
        treeMap[row][col-1] == '.' or treeMap[row][col+1] == '.'):
        solvedTreePos += [pos]
        treeMap[row][col] = 1
for pos in solvedTreePos:
    treePos.remove(pos)
solvedTreePos = []

#print("total non 1 Trees", len(treePos))

# Solve for all treeNum != 1, starting from 2
currTreeNum = 2
while(treePos != []):
    # Solve for tree
    for pos in treePos:
        row, col = pos
        if (treeMap[row-1][col] == currTreeNum-1 or 
            treeMap[row+1][col] == currTreeNum-1 or 
            treeMap[row][col-1] == currTreeNum-1 or 
            treeMap[row][col+1] == currTreeNum-1):
            treeMap[row][col] = currTreeNum
            solvedTreePos += [pos]
    
    # Clear solved trees
    for pos in solvedTreePos:
        treePos.remove(pos)
    solvedTreePos = []
    currTreeNum += 1

    #print("tree", currTreeNum, len(treePos))


    
if currTreeNum > 10:
    printTreeMap_B()
else:
    printTreeMap_S()
