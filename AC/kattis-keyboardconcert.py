'''
kattis-keyboardconcert

- fairly straightforward DP problem

- We want to try every possible (viable) instrument for every note and find the minimum number of swaps. DP is possible 
  given relatively small input sizes (<1k)

- The crux of the problem is that if we try all instruments for every note, searching if the note is in
  the instrument is O(num_of_notes), which causes the solution to be 1k^3 = 1B operations, which is clearly too slow.

- The solution to this is to do preprocessing and store informations per note about whihch instruments are
  viable. This preprocesing is roughly 1k^2 = 1M operations, but is only done once. 

Time: O(NM)
Mem: O(NM)
'''
# Receiving input
N, M = map(int, input().split())
instruments = []
for i in range(N) :
    instruments.append([int(x) for x in input().split()][1:])
tune = [int(x) for x in input().split()]

# Preprocessing which instruments are suitable for which notes
notes = []
for i in range(1001) :
    new_note = []
    for x, ins in enumerate(instruments) :
        if i in ins :
            new_note.append(x)
    notes.append(new_note)

# DP for state[BaseCase][Instrument]
memo = [[-1 for _ in range(M)] for _ in range(N)]
def dp(curr_ins, time) :
    # Base Case
    if time >= M - 1 :
        return 0
      
    # Memoized already
    if memo[curr_ins][time] != -1 :
        return memo[curr_ins][time]
    
    # Try swapping for every other instrument
    min_swaps = M + 1
    for inst in notes[tune[time + 1]] :
        if inst != curr_ins :
            min_swaps = min(min_swaps, 1 + dp(inst, time + 1))
        else :
            min_swaps = min(min_swaps, dp(inst, time + 1))

    memo[curr_ins][time] = min_swaps    # Memoize
    return min_swaps

# Try every possible instrument
ans = M + 1
for inst in notes[tune[0]] :
    ans = min(ans, dp(inst, 0))
print(ans)
