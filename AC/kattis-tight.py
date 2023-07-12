'''
kattis-tight

- DP problem, had some trouble initially figuring out state n transition
  but figured it out eventually

- Basically recursive backtracking but with memoization. DP state
  is number of digits left and curr digit. transition is adding
  a number such that word remains tight. DP returns number of tight
  words with len (length) and last digit (currDigit).

Time: O(N*K)
Space: O(N*K)
'''
import sys
sys.setrecursionlimit(1000000)
from functools import lru_cache

while (True) :
    try :
        K, N = map(int, input().split())
    except EOFError :
        break

    # DP state is (length of word, last Digit) for # of tight words
    @lru_cache(maxsize=None)
    def DP (length, currDigit) :
        # Base Case, end word
        if length == 0 : return 1
        
        # Number of tight words
        # !!! loop unnecessary can be optimized to just try x-1, x, x+1
        # but somehow this ACed so this improvement was unnecessary
        tightWords = 0
        for prevDigit in range (K+1) :
            if abs(prevDigit - currDigit) <= 1 :
                tightWords += DP(length - 1, prevDigit)

        return tightWords
    
    # To start the word creation, we sum all words starting with 
    # digits 0, 1, ... , K
    def startWord (N, K) :
        answer = 0
        for i in range (K+1) :
            answer += DP(N - 1, i)
        return answer
    
    def totalWords (N, K) :
        return (K+1)**N

    DP.cache_clear()
    print (startWord(N, K) / totalWords(N, K) * 100)
