'''
kattis-secretchamber

- Each letter can go through multiple translations. This question essentially
  wants us to find the transitive closure of the translation function.

- This can be solved easily using floyd warshall. All valid translations are a 
  edge of length 0, while all invalid translations are edges of length INF.

- The shortest path reveals which letters can be translated to each other.

Time: O(26^3) = O(1)
Space: O(26^2) = O(1)
'''
INF = int(10**9)

def floyd(adjmat, N) :
    for k in range(N) :
        for i in range(N) :
            for j in range(N) :
                if (adjmat[i][k] != INF and adjmat[k][j] != INF) :
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j])
    return adjmat

def solve() :
    N, M = map(int, input().split())
    adjmat = [[INF for _ in range(26)] for _ in range(26)]

    for i in range(N) :
        a, b = input().split()
        adjmat[ord(a) - ord('a')][ord(b) - ord('a')] = 0
    
    for i in range(26) :
        adjmat[i][i] = 0

    adjmat = floyd(adjmat, 26)

    for i in range(M) :
        state = True

        word_a, word_b = input().split()

        if len(word_a) != len(word_b) :
            print("no")
            continue
    
        for i in range(len(word_a)) :
            if adjmat[ord(word_a[i]) - ord('a')][ord(word_b[i]) - ord('a')] == INF :
                print("no")
                state = False
                break
        
        if state :
            print ("yes")

solve()
