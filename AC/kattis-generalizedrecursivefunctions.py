'''
kattis-generalizedrecursivefunctions

 - pretty straightforward question, just implement our own recursive f.

 - key points to note is that we need to employ memoization esp for big inputs
   to prevent repeated computation of lower states which can be expensive

Time: O(N^2)
Mem: O(N^2)
'''
N = int(input())

# Receiving inputs
for tc in range(N) :
    params = [int(x) for x in input().split(' ')]
    factors = (len(params) - 2) // 2
    args = [int(x) for x in input().split(' ')]

    memo = [[-1] * 100 for _ in range(100)]

    def f(x, y) :
        if x > 0 and y > 0 :
            if memo[x][y] != -1 :
                return memo[x][y]

            res = 0
            for i in range(factors) :
                res += f(x - params[2*i], y - params[2*i + 1])
            memo[x][y] = res + params[-2]
            return res + params[-2]
        
        else :
            return params[-1]
        
    for a in range(len(args)//2) :
        print(f(args[2*a], args[2*a + 1]))
    print()
