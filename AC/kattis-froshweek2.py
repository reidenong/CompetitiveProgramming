'''
kattis-froshweek2

- because only maximum one task can be done per peace interval, we can use
  greedy to constantly pick the biggest possible task (else that task cannot)
  be done later on

Time: O(N)
Space: O(N)
'''
# Receiving input
N, M = map(int, input().split())
tasks = [int(x) for x in input().split()]
peace = [int(x) for x in input().split()]

# Sort in ascending
tasks.sort()
peace.sort()

# Greedy picking biggest tasks for biggest peaces
taskCounter = 0
while len(peace) > 0 and len(tasks) > 0 :
    
    # Task will never be completed, throw task away
    if len(tasks) > 0 and peace[-1] < tasks[-1] :
        tasks.pop()

    # Task completed
    if len(tasks) > 0 and peace[-1] >= tasks[-1] :
        taskCounter += 1
        peace.pop()
        tasks.pop()

print (taskCounter)

