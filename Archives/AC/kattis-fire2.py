'''
kattis-fire2

- We have a fire spreading and person escaping, but since both move at the same speed we can use BFS.

- We can actually use the same frontier to keep track of both the fire and the person, due to
  the fact that frontier behaves like a queue, ie. if we process the fire first, for all subsequent
  frontiers the fire will always be processed first.

- Note that for this to happen we need to append the start point after the fire as we can only 
  dash out of a room at the same time the fire is spreading to it

- Also note that we only need one "visited" grid to keep track of both fire, walls and person,
  as effectively we are only interested in where the person is allowed to go, and fire, wall, and 
  previous locations fall under the same category of "not allowed".

Time: O(W*H) as we visit each cell once
Space: O(W*H)
'''
def solve() :
    W, H = map(int, input().split())

    # Initialising grid
    room = []
    visited = []
    fire = []
    start = 0
    for r in range(H) :
        line = [x for x in input()]
        room.append(line)
        visited.append([0 for x in range(W)])
        for c in range(W) :
            if line[c] == '*' :
                fire.append((r, c, 0))
            elif line[c] == '@' :
                start = (r, c, 1)
            elif line[c] == '#' :
                visited[r][c] = 1

    # BFS for person and fire
    frontier = fire + [start]       # V impt!! fire first
    time = 0
    while frontier :
        next_frontier = []
        for point in frontier :
            r, c, person = point

            # OOB, if its a person they can escape
            if r < 0 or r >= H or c < 0 or c >= W :
                if person :
                    print(time)
                    return
                continue
            
            # If its a wall, fire or visited, ignore
            if visited[r][c] == 1 :
                continue

            visited[r][c] = 1
            next_frontier.append((r+1, c, person))
            next_frontier.append((r-1, c, person))
            next_frontier.append((r, c+1, person))
            next_frontier.append((r, c-1, person))
            
        frontier = next_frontier
        time += 1
    
    print("IMPOSSIBLE")
            

TC = int(input())
for tc in range(TC) :
    solve()
