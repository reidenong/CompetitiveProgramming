'''
CF 
'''
def solve() :
    N, K = map(int, input().split())
    health = [int(x) for x in input().split()]
    pos = [int(x) for x in input().split()]
    monster_raw = []
 
    for i in range(N) :
        monster_raw.append([abs(pos[i]), health[i]])
    monster_raw.sort(reverse=True)
 
    monster = []
    # Merge monsters with same position
    for i in range(N) :
        if len(monster) == 0 :
            monster.append(monster_raw[i])
        else :
            if monster[-1][0] == monster_raw[i][0] :
                monster[-1][1] += monster_raw[i][1]
            else :
                monster.append(monster_raw[i])
 
 
    # Simulate per turn actions
    time = 0
    while (len(monster) > 0) :
        time += 1
        shots = K
 
        # Shoot all bullets
        while shots > 0 and len(monster) > 0 :
            m = monster.pop()
 
            # monster is not killed
            if m[1] > shots :
                m[1] -= shots
                break
 
            # monster is killed with spare shots
            elif m[1] < shots :
                shots -= m[1]
                if len(monster) == 0 :
                    print("YES")
                    return
 
            # Monster is killed just nicely, consider next monster
            elif len(monster) > 0 :
                m = monster.pop()
                break
 
            # Monster is killed just nicely, no monsters left
            else :
                print("YES")
                return
            
        if m[0] <= time :
            print("NO")
            return
    
        monster.append(m)
 
        
 
    print("YES")
 
 
TC = int(input())
for test in range(TC) :
    solve()
