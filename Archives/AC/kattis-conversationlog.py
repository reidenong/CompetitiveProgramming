'''
kattis-conversationlog

- mapping name: Vocabulary means when finding words, there is a
  need to iterate through every person vocabulary for every word,
  which is too slow
- Better to map the word: people who used it with set and then get
  size which shows number of people who used it
- STL sort is stable, so sort lexographically before sorting by 
  frequency ranking

'''
# Initializing Data Structures
names = set([])
wordFreq = {}       # Map. word: frequency
wordName = {}       # Map. name: people who used it

N = int(input())

# For all words
for i in range(N):
    line = input().split()
    name = line[0]
    names.add(name)
    words = line[1:]

    # Update nameVocab, overall wordFreq
    for word in line:
        if not word in wordFreq:
            wordFreq[word] = 0
        wordFreq[word] += 1

        if not word in wordName:
            wordName[word] = set([])
        wordName[word].add(name)

# Determining if word was used by everybody
rankings = []
N = len(names)
for word in wordName:
    if len(wordName[word]) == N:
        rankings += [[word, wordFreq[word]]]

# Sorting rankings
rankings.sort(key=lambda x : x[0])                  # Lexo order
rankings.sort(key=lambda x : x[1], reverse=True)    # Freq order
for rank in rankings:
    print(rank[0])

# No suitable
if len(rankings) == 0:
    print("ALL CLEAR")
