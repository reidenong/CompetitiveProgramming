'''
kattis-sellingspatulas

- Super irritating qn to deal with floating points and stuff.

- we want to get the maxsum between two sales, with the cost of keeping shop open
  inbetween those two sales. We cannot just integrate cost of keeping shop open and profit
  as then it will either open the shop too long or close it

- The easy way is to add cost of keeping shop open into the profit list as a negative
  value. Like this we can just do regular kadane instead of having to deal with the 
  nuances that come with manual addition of costs and profits

Time: O(N)
Space: O(N)
'''
import sys

# Helper function for accurate rounding to 2dp
def twoDP (x) :
    x = round(x * 100)/100
    if x == int(x) or x*10 == int(x*10) :
        return str(x) + '0'
    return (x)

# For each testcase
while (True) :
    N = int(input())

    # Exit criterion
    if N == 0 :
        sys.exit()

    # Receive input
    profits = []
    timings = []
    prevTime = 0
    for i in range (N) :
        time, profit = map(float, input().split())
        timings.append(int(time))
        profits.append((time - prevTime) * -0.08)
        profits.append(profit)
        prevTime = time

    # 1D Max Sum, Kadane
    currSum = 0
    maxSum = 0
    for i, profit in enumerate(profits) :
        currSum += profit
        
        # Restart when below or at 0 (to get shortest sum)
        if currSum <= 0 :
            currSum = 0
            start = i

        # New max sum, save coords
        if currSum > maxSum :
            maxSum = currSum
            end = i
            coords = [start, end]

    # Output answer
    # No profits
    if maxSum <= 0.08 :
        print ("no profit")

    # Max profit is from a single  sale
    elif maxSum in profits :
        idx = (profits.index(maxSum)) // 2
        print (twoDP(maxSum - 0.08), timings[idx], timings[idx])
    
    # Output start, end
    else :
        start = coords[0]//2        # Convert coords to start/end
        end = (coords[1]-1)//2
        print (twoDP(maxSum - 0.08), timings[start], timings[end])
