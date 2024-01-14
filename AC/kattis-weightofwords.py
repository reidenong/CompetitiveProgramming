'''
kattis-weightofwords

 - Easy question, first check if the word is impossible ie. less weight than a...aaa or
   more weight than z...zzz.

 - Else given that the word is possible, we can just create a array of len(L), then just
   allocate points in W to each index to a max of 26.

 - Given each array has a number between 0 and 27, find the letter translation with ascii

Time: O(W)
Mem: O(L)
'''
L, W = map(int, input().split())

# Impossible criterion
if W < L or W > L*26 :
    print('impossible')
    exit()

# Word is definitely possible
ans = [1 for _ in range(L)]

W -= L
for i in range(L) :
    incr = min(25, W)
    ans[i] += incr
    W -= incr

    if W == 0 :
        break

ans = [chr(x + 96) for x in ans]
print(''.join(ans))
