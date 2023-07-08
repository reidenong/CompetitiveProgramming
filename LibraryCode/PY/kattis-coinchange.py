'''
O(NV) Coin Change (Complete search variant)

- DP returns the number of coins needed for each
  price

Time, Space: O(NV)
'''
import sys
from functools import lru_cache
sys.setrecursionlimit(int(1e9))

coins = [1,2,3,4,10]

# DP CoinChange (true minimum)
@lru_cache(maxsize=None)
def DP (price) :
    # Base cases
    if price == 0 : return 0
    if price < 0 : return 2e9
        
    minCoins = 2e9
    for coin in coins :
        minCoins = min(minCoins, 1 + DP(price - coin))
    return minCoins


print (DP(20))

