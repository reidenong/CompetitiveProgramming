'''
codeforces-1978B New Bakery

- Observe that the input is 10^9. This means that we need a log(N) solution.

- We realise that we can get the value(n, a, b, k) in O(1) time by using
  the mathematical formula instead of simulations.

- Furthermore, the value formula is a quadratic equation. This means that we 
  are trying to find a single peak in the range of [0, min(n, b)].

- Then we can BSTA over the whole range of min(n, b) to do peak finding.

Time: O(log N)
Mem: O(1)
'''
def value(n, a, b, k) -> int :
    return (k * (b + 1)) - (k * (k + 1) // 2) + ((n - k) * a)

def solve() :
    N, A, B = map(int, input().split())

    # Binary search over the range of [0, min(N, B) + 1]
    start = 0
    end = min(N, B)
    while start < end :
        mid = start + (end - start) // 2
        if value(N, A, B, mid) > value(N, A, B, mid + 1) :
            end = mid
        else :
            start = mid + 1
    
    print(value(N, A, B, start))

TC = int(input())
for _ in range(TC) :
    solve()
