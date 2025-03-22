'''
codeforces-1974C Beautiful Triple Pairs

- For every pair of triples, we sort them by a combination of 2 of their elements, then compare 
  the third element.

- We put the 3rd element into groupings where each grouping can go together to form a pair.

- in counting the number of pairs in a set of groupings, consider a grouping of [a,b,c,d].

  Number of pairs = a(b+c+d) + b(c+d) + c(d)

  This can be done efficiently by using prefix sums with a linear pass.

Time: O(N log N)
Mem: O(N)
'''
# Return pairs between any 2 groupings given a array of groups
def product(arr) :
    prod = 0
    curr_sum = 0
    for i in range(len(arr)) :
        prod += arr[i] * curr_sum
        curr_sum += arr[i]
    return prod
 
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]
    triples = []
 
    for i in range(N - 2) :
        triples.append((arr[i], arr[i + 1], arr[i + 2]))
     
    ans = 0
    # Compare for each combination YXX
    combis = [(0, 1, 2), (1, 2, 0), (2, 0, 1)]
    for combi in combis :
        # Sort triples by 2 given indices
        triples.sort(key=lambda x: x[combi[0]])
        triples.sort(key=lambda x: x[combi[1]])
        triples.sort(key=lambda x: x[combi[2]])

        # Count number of beautiful pairs
        triples_set = []
        duplicates = 1
        for i in range(N - 3) :
            if (triples[i][combi[1]] == triples[i+1][combi[1]] and
                triples[i][combi[2]] == triples[i+1][combi[2]]) :
            
                if triples[i][combi[0]] == triples[i+1][combi[0]] : 
                    duplicates += 1
            
                else :
                    triples_set.append(duplicates)
                    duplicates = 1
            
            else :
                triples_set.append(duplicates)
                if len(triples_set) > 1 :
                    ans += product(triples_set)
            
                triples_set = []
                duplicates = 1
        
        triples_set.append(duplicates)
        if len(triples_set) > 1 :
            ans += product(triples_set)
        
    print(ans)
 
TC = int(input())
for test in range(TC) :
    solve()
