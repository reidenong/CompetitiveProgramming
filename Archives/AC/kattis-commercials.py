'''
kattis-commercials

- textbook Kadane implementation

Time: O(N)
Space: O(N)
'''
N, P = map(int, input().split())

commercials = [int(x)-P for x in input().split()]

# 1D Max Range Sum (Kadane's algorithm)
def MaxRangeSum (arr) :
    currSum = 0
    currMax = 0
    for elem in arr :
        currSum += elem

        # Better to start from 0 than negative Sum
        if currSum < 0 :
            currSum = 0
            continue
        
        # Update Maximum
        currMax = max(currMax, currSum)

    return currMax

print (MaxRangeSum(commercials))
