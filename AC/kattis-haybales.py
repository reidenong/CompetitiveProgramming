'''
kattis-haybales

- We want to move all P to the right of the string, and all
  C to the left. Our way of moving in 3 has a limited number of possible sequences.

- for example 'PCC' -> 'CCP' & 'PPC' -> 'CPP' effectively have a 'moving value' of 2 as
  we move P 2 steps in the correct direction, and likewise for C

- meanwhile, 'CPC' -> 'CCP' & 'PCP' -> 'CPP' effectively have a'moving value' of 1 as P/C
  are only moved 1 unit in their respective directions

- Thus we greedily pick the highest moving value moves to be done first, then if left with no choice
  we may do moves with a value of 1.

- Shortest code among all kattis users (192 chars)

Time: O(N * number_of_moves) (?)
Mem: O(1)
'''
h=input();m=0
while h!=''.join(sorted(h)):
    for x in ['PCC','PPC','CPC','PCP']:
        if x in h:
            h=h.replace(x,''.join(sorted(x)),1)
            break
    m+=1
print(m)
