arr = [1,0,0]
def A():
    container = arr[1]
    arr[1] = arr[0]
    arr[0] = container
    
def B():
    container = arr[2]
    arr[2] = arr[1]
    arr[1] = container
    
def C():
    container = arr[2]
    arr[2] = arr[0]
    arr[0] = container

actions = input()
for action in actions:
    if action == "A":
        A()
    elif action == "B":
        B()
    else:
        C()

print(arr.index(1) + 1)
