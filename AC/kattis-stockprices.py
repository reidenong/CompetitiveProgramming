'''
kattis-stockprices

- use 2 priority queues to maintain asks and bids as you are always
  looking for the smallest ask and largest bid
- use a Direct Addressing Table to keep track of the quantity of 
  each ask/bid and use it to remove items from those queues as needed
- important to not maintain duplicates in heapQ, not that it breaks 
  heapQ but it affects the way we process sales (refer to code)

Time: O(n log n) 

'''
import heapq

tc = int(input())
for _ in range(tc):
    # Initializing DSes
    asksPrice = []      # Smallest first
    bidsPrice = []      # Largest first, flipped values with *-1

    # DAT for qty of each stock since x,y is small (<1k)
    asksQty = [0]*1001  # Indexed-0
    bidsQty = [0]*1001

    N = int(input())
    si = '-'
    for i in range(N):
        
        order = input().split()
        quantity = int(order[1])
        price = int(order[4])

        # Buy order, update bids
        if order[0] == "buy":
            bidsQty[price-1] += quantity
            if not -1*price in bidsPrice:
                heapq.heappush(bidsPrice, -1*price)
        
        # Sell order, update asks
        else:
            asksQty[price-1] += quantity
            if not price in asksPrice:
                heapq.heappush(asksPrice, price)

        # Check for sales
        while(len(bidsPrice) != 0 and 
              len(asksPrice) != 0 and
              -1*bidsPrice[0] >= asksPrice[0]):
            si = asksPrice[0]
            quantitySold = min(bidsQty[-1*bidsPrice[0]-1],
                            asksQty[asksPrice[0]-1])
            bidsQty[-1*bidsPrice[0]-1] -= quantitySold
            asksQty[asksPrice[0]-1] -= quantitySold

            # Updating DATs if qty is exhausted
            if bidsQty[-1*bidsPrice[0]-1] == 0:
                heapq.heappop(bidsPrice)
            if asksQty[asksPrice[0]-1] == 0:
                heapq.heappop(asksPrice)
        
        # Ask Bid Stock price
        if asksPrice != []:
            ai = asksPrice[0]
        else:
            ai = '-'
        if bidsPrice != []:
            bi = -1*bidsPrice[0]
        else:
            bi = '-'
        print(ai, bi, si)


        
