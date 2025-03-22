'''
kattis-delivery

- Greedily deliver to the furthest possible location since we 
  must go there either way. Try to deliver as much as we can on
  the way back
- Remember to multiply the mileage by 2 as if you go there you
  must go back the same distance

Time: O(total_mail / capacity)
Space: O(N)
'''
# Receiving input
N, capacity = map(int, input().split())

# Differentiating negative and positive coordinates
left, right = [], []
for i in range (N) :
    location = [int(x) for x in input().split()]
    if location[0] < 0 :
        left.append([abs(location[0]), location[1]])
    else :
        right.append(location)

# Send mail
def sendMail (locations) :
    mileage = 0
    locations.sort()

    # Greedily deliver to the furthest location
    while len(locations) > 0 :
        locations[-1][1] -= capacity
        mileage += locations[-1][0]

        # Furthest location still not empty
        if locations[-1][1] > 0 :
            continue

        # Emptied furthest location
        if locations[-1][1] == 0 :
            locations.pop()
        
        # Surplus, delivering remainder on returning trip
        elif locations[-1][1] < 0 :
            mail = abs(locations[-1][1])
            locations.pop()
            while len(locations) > 0 :
                locations[-1][1] -= mail

                # Deliver some of the next trips mail
                if locations[-1][1] > 0 :
                    break

                # Nicely finish all the mail of the next trip
                if locations[-1][1] == 0 :
                    locations.pop()
                    break
                
                # Complete this location's mail too, with surplus
                elif locations[-1][1] < 0 :
                    mail = abs(locations[-1][1])
                    locations.pop()
    
    # If they travel there they must travel back
    return mileage*2
                
# Find total mileage
print (sendMail(left) + sendMail(right))
