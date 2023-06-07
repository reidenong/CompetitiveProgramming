'''
kattis-cardtrick2

- also possible to complete search given small Q and small N < 13
- easier to code simulation tho
'''
from collections import deque

# Get a viable deck for given length N by reverse simulation
def solveDeck (N) :
    def reverseShuffle (deck) :
        deck.appendleft(deck.pop())

    deck = deque([N])
    for i in reversed (range (1, N)) :
        deck.appendleft(i)
        for j in range (i):
            reverseShuffle(deck)
    deck = [str(x) for x in deck]
    print (' '.join(deck))
    
# Process each input case
testcases = int(input())
for i in range(testcases) :
    N = int(input())

    solveDeck(N)
