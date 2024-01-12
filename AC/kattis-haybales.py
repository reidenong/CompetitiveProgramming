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

- Shortened code as i was competing for the shortest possible code. Code here is 257 chars, but 
  winner has 205. lmk if u figure a way to shorten it further.

Time: O(N * number_of_moves) (?)
Mem: O(1)
'''
h=input();f=''.join(sorted(h));m=0
while h!=f:
    if 'PCC' in h:h=h.replace('PCC','CCP',1)
    elif 'PPC' in h:h=h.replace('PPC','CPP',1)
    elif 'CPC' in h:h=h.replace('CPC','CCP',1)
    elif 'PCP' in h:h=h.replace('PCP','PPC',1)
    m+=1
print(m)
