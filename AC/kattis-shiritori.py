'''
kattis-shiritori

- use python set, list too slow: will TLE

'''
import sys
words = set([])

N = int(input())

for i in range(N):
    word = input()
    if i > 0:
        if word[0] != letter:
            print("Player", (i%2)+1, "lost")
            sys.exit()
        if word in words:
            print("Player", (i%2)+1, "lost" )
            sys.exit()
    letter = word[-1]
    words.add(word)

print("Fair Game")
        
