'''
kattis-trollhunt

- dont have to search the original bridge

Time: O(1)
Space: O(1)
'''
import math
B, K, G = map(int, input().split())
N = math.floor(K/G)
print (math.ceil((B-1)/N))


