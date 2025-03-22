'''
codeforces-1981B Turtle and an Infinite Sequence

- The case where M = 0 is trivial, as the answer will be N

- The first step is to observe that even though all the numbers in the sequence are
  mutating simultaneously, after m seconds, the set of things we want to OR together
  will be (a_(N -M), ... , a_(N) , ... , a_(N + M))

- ie we want to find (a_(N - M) | ... | a_(N) | ... | a_(N + M))

- Next consider our smallest number, a_(N - M) and our largest number, a_(N + M).
  We realise that the largest number will have some bit differences with the smallest 
  number

- Observe that after the first (most significant) bit difference, all the other
  bits before that will have to have been at 1 at some point in the sequence, eg.
  from 10000 to 10100, somewhere along the sequence the number wld have gone thru
  10001, 10010, 10011, 10100. This means the after the first bit difference, the
  rest of the bits will be 1.

Time: O(1)
Mem: O(1)
'''
def solve() :
	N, M = map(int, input().split())

	# trivial case, ans = N
	if M == 0 :
		print(N)
		return
	
	# Get the binary representation of N
	start = bin(max(N - M, 0))[2:]
	end = bin(N + M)[2:]
	
	# Regulate the length of the binary representation to be 32
	start = '0' * (32 - len(start)) + start
	end = '0' * (32 - len(end)) + end
	
	# Find the first bit difference between start and end
	ans = ''
	for i in range(32) : 
		if end[i] == '1' and start[i] == '0' :
			ans = end[:i] + '1' * (32 - i)
			break
		
	# Convert ans back to decimal
	ans = int(ans, 2)
	print(ans)

tc = int(input())
for _ in range(tc) :
	solve()
