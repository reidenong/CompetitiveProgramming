import sys

# Initializing Chessboard Axes
xaxis = [0, 0, "A", "B", "C", "D", "E", "F", "G", "H", 0, 0]
yaxis = [0, 0]
for x in range(1,9,1):
    yaxis += [str(x)]
yaxis += 2*[0]


def AllDiagonals(X):
    diagonals = []

    xp,yp = xaxis.index(X[0]), yaxis.index(X[1])
    # print(xp, yp)

    for xfactor in [-1,1]:
        for yfactor in [-1,1]:
            xp,yp = xaxis.index(X[0]), yaxis.index(X[1])
            while(xaxis[xp] != 0 and yaxis[yp] != 0):
                xp += xfactor
                yp += yfactor
                if(xaxis[xp] != 0 and yaxis[yp] != 0):
                    diagonals += [str(xaxis[xp]) + str(yaxis[yp])]
            
    return(diagonals)


N = int(sys.stdin.readline())
counter = 0

for line in sys.stdin:
    input = line.split(" ")

    startpoint = str(input[0] + input[1])
    endpoint = str(input[2] + input[3]).strip()

    startdiagonals = AllDiagonals(startpoint)
    enddiagonals = AllDiagonals(endpoint)

    if(startpoint == endpoint):
        print("0 " + startpoint [0] + " " + startpoint[1])
    elif(endpoint in startdiagonals):
        print("1 " + startpoint[0] + " " + startpoint[1] + " " + endpoint[0] + " " + endpoint[1])
    elif(len(set(startdiagonals).intersection(enddiagonals)) != 0):
        s =  set(startdiagonals).intersection(enddiagonals)
        midpoint = next(iter(s))
        print("2 " + startpoint[0] + " " + startpoint[1] + " " + midpoint[0] + " " + midpoint[1] + " " + endpoint[0] + " " + endpoint[1])
    else:
        print("Impossible")





    
