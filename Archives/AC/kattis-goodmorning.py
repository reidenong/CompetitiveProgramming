'''
kattis-goodmorning

- as you want the nearest number, start at K and slowly move away from
  K, testing legality at each point. as you are moving away from K,
  the first lega number is guaranteed to be the closest

Time: O(N)
Space: O(N)
'''
# Legal number checker
# Shows where each number can move to
legalMoves = [[0],
              [1,2,3,4,5,6,7,8,9,0],
              [2,3,5,6,8,9,0],
              [3,6,9],
              [4,5,6,7,8,9,0],
              [5,6,8,9,0],
              [6,9],
              [7,8,9,0],
              [8,9,0],
              [9]]

# Returns legality of a number              
def legal (x) :
    x = [int(i) for i in str(x)]

    # Inspect legality of move between every adjacent digit
    for i in range (len(x) - 1) :
        if not x[i+1] in legalMoves[x[i]] :
            return False

    return True


# For each testcase
TC = int(input())
for testcase in range (TC) :
    K = int(input())

    # Iterating further away from the number, test for the legality
    for i in range (K) :
        if legal(K + i) :
            print (K + i)
            break
        elif legal(K - i) :
            print (K - i)
            break
