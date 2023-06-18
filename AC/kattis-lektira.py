'''
kattis-lektira

- just do as qn says, set to reduce dupes

Time: O(N^2)
Space: O(N^2)
'''
P = set()
word = input()
N = len(word)

# Try all cutting points, add to set to remove duplicates
for i in range (1, N-1) :
    for j in range (1, N - i) :
        word1 = word[:i]
        word2 = word[i:][:j]
        word3 = word[i:][j:]
        P.add(word1[::-1] + word2[::-1] + word3[::-1])

# Print first entry of sorted set
print(sorted(P)[0])
