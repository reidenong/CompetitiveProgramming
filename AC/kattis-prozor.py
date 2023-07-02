'''
kattis-prozor

- fixed range so just complete search given small R,S <= 100

Time: O(N^2)
Space: O(N^2)
'''
# Receiving input
R, S, K = map(int, input().split())
window = []
for i in range(R) :
    row = list(input())
    window.append(row)

# Fixed 2D Max Sum
def QueryFlies (row, col) :
    flies = 0
    for i in range (row+1, row+K-1) :
        for j in range (col+1, col+K-1) :
            if window[i][j] == '*' :
                flies += 1
    return flies

# Find max number of flies
maxFlies = 0
for row in range (R-K+1) :
    for col in range (S-K+1) :
        flies = QueryFlies(row, col)
        if flies > maxFlies :
            coords = [row, col]
            maxFlies = flies
print (maxFlies)

# Printing racket on window
# Printing racket corners
row, col = coords
window[row][col] = "+"
window[row+K-1][col] = "+"
window[row][col+K-1] = "+"
window[row+K-1][col+K-1] = "+"

# Printing racket edges
for i in range (row+1, row+K-1) :
    window[i][col] = "|"
for i in range (row+1, row+K-1) :
    window[i][col+K-1] = "|"
for i in range (col+1, col+K-1) :
    window[row][i] = "-"
for i in range (col+1, col+K-1) :
    window[row+K-1][i] = "-"

# Printing window
for row in window :
    print (''.join(row))
