'''
kattis-vegetables

- We just need to maintain that the smallest/largest is larger than 
  threshold T. This is best done by tracking the relative sizes of the
  individual pieces, such that at any given point sorting the array 
  gives us the piece sizes and to check the requirement we just take
  the first and alst element of array

- Another observation is that given the chance to indefinitely many cuts 
  on a given piece of fruit, the best way to cut is into equal sizes, ie
  with piece length 6, 2 cuts gives us 3 of length 2, 5 cuts gives us 
  6 pieces of length 1 etc. as any other method results in wider variance 
  in piece size, which is not what we want as we are trying to minimise
  number of cuts

- Thus, sorting the sizes of vegetables, we greedily choose the largest
  piece and cut it into one more piece than previously, ensuring that the
  size of the largest piece is always being reduced in a manner that 
  minimises the number of needed cuts.

- Possible speedup is to use Priority queue (heapq for python) as log N
  operations are faster but given easy requirements (<=500 cuts, <=1000 N) 
  N log N sorting is fine

Time: O(500 * N log N) = O(N log N) for STL sort
Space: O(N)
'''
# Helper functions 
def ratio (A, B) :
    return min(A, B) / max(A, B)
def querySize (x) :
    return x[0] / (x[1] + 1)

# Receiving input
T, N = [float(x) for x in input().split()]
N = int(N)
pieces = [[int(x), 0] for x in input().split()]

# Constantly cut the largest piece
cuts = 0
while (True) :
    # Sort pieces by relative size
    pieces.sort(key=lambda x : x[0] / (x[1] + 1))

    # Satisfied
    if ratio(querySize(pieces[0]), querySize(pieces[-1])) >= T :
        break

    # Cut biggest piece into more pieces
    largest = pieces.pop()
    pieces.append([largest[0], largest[1] + 1])
    cuts += 1

print (cuts)
