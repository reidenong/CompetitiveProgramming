'''
O(N) Kadane's Algorithm for 1D Max RangeSum
'''
def Kadane (arr) :
    currSum = 0
    maxSum = 0
    for elem in arr :
        currSum += elem

        # Better to start from 0 than negative sum
        if currSum < 0 :
            currSum = 0
            continue

        # Update maximum
        maxSum = max(currSum, maxSum)

    return maxSum
