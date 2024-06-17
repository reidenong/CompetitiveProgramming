'''
kattis-queens

- check if a queen can be put there, then place it

Time: O(N^2)
Memory: O(N^2)
'''
import sys

def solve() :
    N = int(input())

    board = [[0 for _ in range(N)] for _ in range(N)]

    for _ in range(N) :
        row, col = map(int, input().split())

        # Check row
        for i in range(N) :
            if board[row][i] :
                print("INCORRECT")
                return
    
        # Check col
        for i in range(N) :
            if board[i][col] :
                print("INCORRECT")
                return
            
        # Check diagonal, each column
        for i in range(N) :
            if row + i < N and col + i < N and board[row + i][col + i] :
                print("INCORRECT")
                return
            
        for i in range(N) :
            if row + i < N and (-1 < col - i < N) and board[row + i][col - i] :
                print("INCORRECT")
                return
            
        for i in range(N) :
            if (-1 < row - i < N) and (-1 < col - i < N) and board[row - i][col - i] :
                print("INCORRECT")
                return
            
        for i in range(N) :
            if (-1 < row - i < N) and col + i < N and board[row - i][col + i] :
                print("INCORRECT")
                return

        # Add queen        
        board[row][col] = 1

    print("CORRECT")

solve()
