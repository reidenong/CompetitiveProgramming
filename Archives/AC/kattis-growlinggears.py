'''
kattis-growlinggears

- to get maximum point, just complete the square to find
  R = (b/2a) and the maximum point is at (b^2/4a) + C

Time: O(N)
Space: O(N)
'''
# For each testcase
testCase = int(input())
for tc in range (testCase) :
    N = int(input())

    # Receiving input for each engine
    maxPoints = []
    for i in range (N) :
        A, B, C = map(int, input().split())
        maxPoints.append(((B**2)/(A*4)) + C)

    # Output maximum
    maxIdx = maxPoints.index(max(maxPoints))
    print (maxIdx + 1)


