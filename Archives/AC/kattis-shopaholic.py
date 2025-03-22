'''
kattis-shopaholic

- greedily pick top3 costly items and add the lowest item to discount

Time: O(N)
Space: O(N)
'''
N = int(input())
prices = [int(x) for x in input().split()]
prices.sort()

discount = 0
while len(prices) > 2 :
    prices.pop()
    prices.pop()
    discount += prices.pop()

print(discount)
