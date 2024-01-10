'''
kattis-janeeyre

- simple question which requires a number of DSes to solve efficiently.

- Since we want to always take the lexi-first book, we can use PQ to easily get the next
  book in an efficient time ~O(logN)

- To maintain the lengths of each book, we use a hashmap to store book name to the book length

- To maintain the given books, we can use a list of pairs of book name and time given, sorting by time given

Time: O((N + M)log(N + M))
Mem: O(N + M)
'''
import heapq

# Receiving input
N, M, K = map(int, input().split())
book_q = []
given_q = []
book_lengths = {}

# Initialize book queue
heapq.heappush(book_q, "Jane Eyre")
for _ in range(N) :
    line = input().split('"')[1:]
    line[1] = int(line[1])
    heapq.heappush(book_q, line[0])
    book_lengths[line[0]] = line[1]

# Initialize given book queue, also sort by time
for _ in range(M) :
    line = input().split('"')
    line[0] = int(line[0])
    line[2] = int(line[2])
    given_q.append([line[1], line[0]])
    book_lengths[line[1]] = line[2]
given_q.sort(key = lambda x : x[1])

# Simulate book reading
time = 0
while True :
    curr_book = heapq.heappop(book_q)

    if curr_book == "Jane Eyre" :
        print(time + K)
        break

    time += book_lengths[curr_book]

    # Add given books if time is appropriate
    while given_q and given_q[0][1] <= time :
        heapq.heappush(book_q, given_q.pop(0)[0])
