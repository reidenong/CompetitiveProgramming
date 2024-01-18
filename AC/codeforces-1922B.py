'''
CF-1922B Forming Triangles

- Observe that in order to form a non degenerate triangle, for a triangle with sides a,b,c in increasing length, a + b must 
  be greater than c.

- Considering that all the sticks have a length of 2^i, this implies that to create a triangle, we need at least 2 sticks of
  length 2^i paired with one stick of any smaller length to make a triangle. A single stick of length 2^i with only sticks 
  shorter than it is unable to make any triangles

- We repeatedly gather the largest sticks of the same length, and within this K pool of largest sticks, we can form KC3 triangles
  picking among the pool and KC2 * remaining stick pool triangles.
  
Time: O(N)
Mem: O(N)
'''
TC = int(input())
for tc in range(TC) :
    N = int(input())
    sticks = [int(x) for x in input().split()]

    sticks.sort()
    ways = 0
    while len(sticks) >= 3 :
        curr_stick_counter = 0
        curr_stick = sticks[-1]

        # Gather all the longest sticks together, we can make a triangle if we have at least 2 here.
        while sticks and sticks[-1] == curr_stick :
            curr_stick_counter += 1
            sticks.pop()

        # Ways to create triangles among stick of all same length
        if curr_stick_counter >= 3 :
            ways += curr_stick_counter * (curr_stick_counter - 1) * (curr_stick_counter - 2) // 6

        # Ways to create triangles with a single stick from the smaller pile
        if curr_stick_counter >= 2 :
            ways += len(sticks) * curr_stick_counter * (curr_stick_counter - 1) // 2 
        
    print(ways)
