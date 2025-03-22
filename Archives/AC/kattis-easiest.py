'''
kattis-easiest

- bruteforceable as 10 < p <= 100

Time: O(90*N) = O(N)
Space: O(1)
'''
# Helper function to return sum of digits
def sumDigits (X) :
    return sum([int(x) for x in str(X)])

# For each testcase
while (True) :
    N = int(input())
    if N == 0 :
        break

    # Bruteforce all P smaller than 100
    digitSum = sumDigits(N)
    for p in range (11, 101) :
        if digitSum == sumDigits(N * p) :
            print(p)
            break



