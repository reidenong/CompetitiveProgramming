'''
kattis-stockbroker

- We want to buy low, sell high. This is achieved through breaking down the price
  sequence into intervals of strictly increasing prices. Every interval is a opportunity
  to gain money by buying low at the start and selling high
  
- We buy all at the start of the interval, where the price is at a low. As the sequence is 
  strictly increasing, we will not be able to buy any stock after the low with the 
  leftover money. We sell the stock at the end of the sequence, the high. 
  By definition of strictly increasing, the end of the interval means the 
  start of the next interval is lower and thus more money is earned selling at a high

- Ignore all intervals of length one, there is no opp to make money there

- Remember that we cannot hold more than 100k stock at any given time

Time: O(N)
Space: O(N)
'''
from collections import deque

D = int(input())

# Group the prices in subsequences of strictly increasing prices
pricesIncr = []
prices = []
for i in range (D) :
    price = int(input())

    # Start new increasing group
    if len(prices) == 0 or price > prices[-1]:
        prices.append(price)
    
    # Start new increasing group
    else :
        pricesIncr.append(prices)
        prices = [price]
pricesIncr.append(prices)

# Buy and Sell over every period of strictly increasing prices
money = 100
for interval in pricesIncr :

    # No opportunity for profit
    if len(interval) == 1 :
        continue

    # Buy low, sell high
    buy = interval[0]
    sell = interval[-1]

    # Selling and Buying stocks
    stocksBought = min(100000, money//buy)      # Calculate number of stocks bought
    money -= stocksBought * buy                 # Account for cost of buying stocks
    money += stocksBought * sell                # Add Profit from selling stock

print (money)
