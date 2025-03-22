'''
kattis-esej

- important to use upperbound B as A might be smaller than B/2
  which means A will fail the vocabulary requirement.
- probably unnecessary to use set to ensure 'distinct' letters as
  the probability of having half your words the same with random 
  length and random permutation of letters is definitely negligible.

Time: O(B)
Space: O(B)

'''
import sys
import random
alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
             'u', 'v', 'w', 'x', 'y', 'z']

A, B = map(int, input().split())

for i in range(B):
    word = ''
    for j in range(random.randint(1,10)):
        word += random.choice(alphabets)
    sys.stdout.write(word)

    if i < B-1:
        sys.stdout.write(' ')
