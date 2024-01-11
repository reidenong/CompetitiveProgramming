'''
kattis-ceremony

 - Fairly straightforward greedy question, issues are more on the implementation side.

 - Greedy works as for each charge, we want to destroy the most floors possible, and this
   allows us to destroy the given floors in the least number of charges. 

 - There are only two moves: to destroy the highest block, or to destroy bottom floor forall blocks.
   For the greedy methodology as stated above, we want to destroy the most amount of floors per charge. So
   if the highest block has more floors than the total number of blocks, we destroy the highest block. Else,
   destroying the bottom floor forall blocks is more efficient.

 - Initial implementation with blocks will definitely TLE due to 100k blocks. We can use a frequency table to 
   cut down on the number of iterations we have to do. Furthermore, to avoid using slow O(N) pop operations, we
   record the number of destroyed floors as well as the index of the highest block we have not destroyed. This 
   manages to pass the time limit.

Time: O(N log N) for sorting
Mem: O(N)

'''
N = int(input())
blocks = [int(x) for x in input().split()]

# Generate frequency table
freq = {}
for block in blocks :
    if block in freq :
        freq[block] += 1
    else :
        freq[block] = 1
freq = sorted([[tup[0], tup[1]] for tup in freq.items()], reverse = True)

# Greedy algo to destroy the most blocks per charge
destroyed_floors = 0
charges = 0
top_idx = 0
while N > 0 :
    charges += 1

    # Destroy top block
    if freq[top_idx][0] - destroyed_floors > N :
        freq[top_idx][1] -= 1
        N -= 1
        if freq[top_idx][1] == 0 :
            top_idx += 1

    # Destroy bottom floor for all blocks
    else :
        destroyed_floors += 1
        if freq[-1][0] == destroyed_floors :
            N -= freq[-1][1]
            freq.pop()

print (charges)
