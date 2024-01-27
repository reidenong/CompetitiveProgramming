'''
codeforces-1925A

- A valid string is (abc)...(abc) for n units

- All substrings will appear here, and this is also the shortest valid string.
'''
alphabet = [chr(i) for i in range(97, 123)]

TC = int(input())
for test in range(TC) :

    N, K = map(int, input().split())

    answer = ""
    for i in range(N) :
        for i in range(K) :
            answer += alphabet[i]

    print(answer)
