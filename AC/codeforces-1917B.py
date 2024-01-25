'''
codeforces-1917B Erase First or Second Letter

- Supposedly a easy problem but i had problems understanding the solution

- The first observation is that if we do a move 2 after a move 1, it is no different from 2 move 1s. With this in mind,
  we note that all possible strings are generated by a sequence of x move 1s followed by y move 2s, where x, y >= 0.

- The second observation is that if all move 1s will result in unique strings, as we are decreasing the length of the string.
  A move 2 will only result in a previously visited string if the the character we are removing has been visited (ie. removed)
  before. This means that we only need to keep track of the characters that have been visited.

  ie. consider abaca. This is a string in itself.
  if we dont remove the first letter, we can do a (move 1) 4 times, resulting in 4 unique strings. (aaca, aca, aa, a)
  if we remove the first letter, we get baca. Then we can do a (move 2) 3 times, resulting in 3 unique strings. (bca, ba, b)
  if we remove the first letter twice, we get aca. but we have visited a, so skip. WE are guaranteed to have something
    to have visited these strings the first time we visited a.
  if we remove the first letter 3 times, we get ca. Then we can do a (move 2) 1 time, resulting in 1 unique string. (c)
  if we remove the first letter 4 times, but we have already visiteed a, so we can skip this. 

Time: O(N)
Mem: O(1)
'''
def solve() :
    N = int(input())
    string = input()

    counter = 0
    visited = {}

    for i in range(N) :
        if string[i] not in visited :
            visited[string[i]] = 1
            counter += N - i

    print(counter)

# Main
TC = int(input())
for _ in range(TC) :
    solve()
