'''
kattis-restaurant

after messing around with a few simulations of drop and take, the final
algorithm feels something like this

- drop plates into pile2 whenever there is a drop
- when take, 
> pile 1 empty: move plates from pile2 to pile1, then take from pile1
> pile 1 has plates: exhaust all pile1 plates, then move from pile2

Stack is actually unecessary here, given that by this algorithm 
pile1 is always in ascending order and pile2 is always in descending 
order hence only necessary to keep track of overall number of plates

Time: O(n)
Space: O(1)
'''
import sys

while(True):
    N = int(input())
    if N == 0:
        sys.exit()

    # Create DSes
    pile1 = 0
    pile2 = 0

    for case in range(N):
        instruction = input().split()
        if instruction[0] == "DROP":
            pile2 += int(instruction[1])
            print("DROP 2 " + instruction[1])

        if instruction[0] == "TAKE":
            if pile1 == 0:
                # pile1 empty, move from pile2 then take
                print("MOVE 2->1 " + str(pile2))
                pile1 = pile2
                pile2 = 0
                pile1 -= int(instruction[1])
                print("TAKE 1 " + instruction[1])
            else:
                instruction[1] = int(instruction[1])
                # All plates taken from pile1
                if instruction[1] <= pile1:
                    print("TAKE 1 " + str(instruction[1]))
                    pile1 -= instruction[1]

                # Not enough in pile1, need to move from pile2 too
                else:
                    print("TAKE 1 " + str(pile1))
                    instruction[1] -= pile1
                    print("MOVE 2->1 " + str(pile2))
                    pile1 = pile2
                    pile2 = 0
                    print("TAKE 1 " + str(instruction[1]))
                    pile1 -= instruction[1]
    print()

                

