'''
CF-1920B Summation Game

- Bob will always use up all multiplications of -1s

- Alice may or may not use up all k removals, but she will always remove the biggest integer

- We determine which integers Bob will multiply first. Then we try to remove the biggest
  integer each time, simulating Bob's reponse to Alice removals by multiplying the next largest
  available integer.

- We keep track of the integers by array indices as maintaining the arrays for O(N^2) time (summing * N actions) 
  is too slow.

Time: O(N)
Mem: O(N)
'''
TC = int(input())
for tc in range(TC) :    
    N, K, X = map(int, input().split())

    arr = [int(x) for x in input().split()]
    arr.sort()

    a_idx = N - X - 1
    b_idx = N - 1

    a_sum = sum(arr[:-X])
    b_sum = sum(arr[-X:])
    max_ans = a_sum - b_sum
    for i in range(K) :
        
        if b_idx == -1 :
            max_ans = max(max_ans, a_sum)
            break

        if a_idx == -1 :
            b_sum -= arr[b_idx]
            b_idx -= 1
            
        else :
            b_sum = b_sum - arr[b_idx] + arr[a_idx]
            a_sum -= arr[a_idx]
            a_idx -= 1
            b_idx -= 1

        max_ans = max(max_ans, a_sum - b_sum)
        
    print(max_ans)
