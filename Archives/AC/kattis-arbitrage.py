'''
kattis-arbitrage

- Arbitrage opportunities arise when there is a cycle of curencies such that the
  product of the exchange rates is greater than 1. As such, in this graph, we need to
  find a way to take the multiples of the edges as we move through them

- Observe for a cycle A -> B -> C -> A, the product of the exchange rates is then

    rate(A, B) * rate(B, C) * rate(C, A). If this is greater than 1, then we have an arbitrage.

- We can apply the log function to achieve this.

    rate(A, B) * rate(B, C) * rate(C, A) > 1
    => log(rate(A, B) * rate(B, C) * rate(C, A)) > log(1)
    => log(rate(A, B)) + log(rate(B, C)) + log(rate(C, A)) > 0
    => -log(rate(A, B)) - log(rate(B, C)) - log(rate(C, A)) < 0

- This way, by converting all edges to their negative log values, we can apply Floyd Warshall and
  search for negative cycles, which would indicate an arbitrage opportunity,

Time complexity: O(N^3)
Space complexity: O(N^2)
'''
from math import log2
import sys

INF = int(10**9)

def floyd(adjmat, N) :
    for k in range(N) :
        for i in range(N) :
            for j in range(N) :
                if (adjmat[i][k] == INF or adjmat[k][j] == INF) :
                    continue
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j])
    return adjmat

def solve() :
    N = int(input())
    if N == 0: sys.exit(0)

    currencies = input().split()
    indices = {currencies[i] : i for i in range(N)}
    
    adjmat = [[INF for i in range(N)] for j in range(N)]
    for i in range(N) :
        adjmat[i][i] = 0

    M = int(input())
    for i in range(M) :
        u, v, ratio = input().split()
        rate = ratio.split(":")
        rate = int(rate[1]) / int(rate[0])
        rate = -log2(float(rate))
        u, v = indices[u], indices[v]
        adjmat[u][v] = rate
    
    adjmat = floyd(adjmat, N)

    # Check for negative cycles
    for i in range(N) :
        if adjmat[i][i] < -0.000001 :
            print("Arbitrage")
            return
    print("Ok")

while True :
    solve()
