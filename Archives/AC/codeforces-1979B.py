'''
codeforces-1979B XOR Sequences

- The first step is to find the bit differences between the two numbers, which can 
  be done with a XOR; z = x xor y

- Now the problem is simplified to finding the differences between the XOR sequence
  of z and the set of all natural numbers

- Observe that for any z, the longest contiguous sequence of numbers which will not 
  get affected would be those which fit in the 0s before the Least Significant Bit
  of z.

Time: O(1)
Mem: O(1)
'''
def solve() :
    x, y = map(int, input().split())
    z = x ^ y

    def LSOne(S) :
        return S & (-S)

    print(LSOne(z))

TC = int(input())
for _ in range(TC) :
    solve()
