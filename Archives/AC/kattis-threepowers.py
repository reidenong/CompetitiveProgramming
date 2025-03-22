'''
kattis-threepowers

 - a seemingly complicated question, it can be solved by several insights

 - firstly, the sum of all powers of 3 up to n is smaller than the threepower of (n + 1).
   eg. 1 + 3 + 9 < 27, 1 + 3 + 9 + 27 < 81 and so on.

 - Additionally, from the property above, we realise that between each proper power of 3,
   ie for the rankings between {27} and {81}, we have {27} + elemnts of powerSet of {1,2,3,9}. Not
   a very clear way of describing it but toy around with the numbers and you'll see the pattern.

 - ie. after sorting the 4th set is {3^1, 3^2}, 8th set is {3^1, 3^2, 3^3} ... 
   in general the nth ranked set is {3^1, ... , 3^n}.

 - combine with the fact that the powerSet of {1,...,3**n} has 2**n elements, given the sorting number N,
   we can find the largest power of 3 there is by removing the largest power of 2. This can be found by the truncation
   of the log2 of N.

 - remember to account for the 1-indexing by subtracting 1 from the original N.

Time: O(log2(N))
Mem: O(1)
'''
from math import log2
while (True) :
    # N - 1 to account for 1-indexing
    N = int(input()) - 1

    # Settle base cases
    if N == -1 : break
    if N == 0 :
        print ("{ }")
        continue

    # Recursively cut down by powers of 2
    powers = []
    while (N > 0) :
        currPow = int(log2(N))
        powers.append(currPow)
        N -= 2**currPow
    
    # Displaying output
    ans = "{"
    while (powers) :
        ans += " " + str(3**powers.pop())
        if (len(powers) > 0) :
            ans += ","
    ans += " }"
    print (ans)
