'''
codeforces-1974B Symmetric Encoding

- cipher forwards and backwards is symmetric and unique

Time/Mem: O(N)
'''
def solve() :
    N = int(input())
    word = list(input())
    letters = list(set(word))
    letters.sort()

    cipher = {}
    
    M = len(letters)
    for i in range(M) :
        cipher[letters[i]] = letters[M - 1 - i]

    for i in range(N) :
        word[i] = cipher[word[i]]
    
    print(''.join(word))

TC = int(input())
for test in range(TC) :
    solve()
