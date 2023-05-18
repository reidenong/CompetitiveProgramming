'''
kattis - 2048

- Rotate the board such that all cases are done L to R
- Slide board first to eliminate gaps
- Merge operations, rightmost first
- Slide board again to close gaps
- Rotate the board back

'''

import sys
board = []

def printBoard(board):
    for line in board:
        print(line)
    print("\n")

def rotateClockwise(board):
    return [list(x) for x in list(zip(*board[::-1]))]

# Receive board input, directional input
for i in range(4):
    board += [[int(x) for x in input().split()]]
moveDir = int(input())

# Adjusting Board for L to R operations
rotateDir = [2, 1, 0, 3] # Translate sliding direction to number of rotations
for i in range(rotateDir[moveDir]):
    board = rotateClockwise(board)
#print("Adjusted Board")
#printBoard(board)

# Sliding Operations
for i in range(4):
    for j in range(3):
        idx = 2-j   # Slide rightmost first
        while(idx < 3):
            if(board[i][idx+1] == 0):
                board[i][idx+1] = board[i][idx]
                board[i][idx] = 0
                idx += 1
            else:
                break

# Merging Operations
for i in range(4):
    for j in range(3):
        idx = 2-j
        if board[i][idx] == board[i][idx+1]:
            board[i][idx+1] = 2*board[i][idx]
            board[i][idx] = 0
#print("Merged Board")
#printBoard(board)

# Sliding Operations
for i in range(4):
    for j in range(3):
        idx = 2-j   # Slide rightmost first
        while(idx < 3):
            if(board[i][idx+1] == 0):
                board[i][idx+1] = board[i][idx]
                board[i][idx] = 0
                idx += 1
            else:
                break
#print("Post-Slide Board")
#printBoard(board)

# Rotating Board back
for i in range(4 - rotateDir[moveDir]):
    board = rotateClockwise(board)

# Displaying Board
for i in range(4):
    line = ""
    for j in range(4):
        line += str(board[i][j]) + " "
    print(line[:-1])
