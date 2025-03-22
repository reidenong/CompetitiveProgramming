while(1):
    N = int(input())
    if N==0:
        break

    names = []
    for i in range(N):
        names += [input()]

    # Python STL sort is stable
    # Use lambda keys to dictate only which letters to use
    # Sort second letter first so first letter will dictate the final priority
    names.sort(key=lambda x : x[1])
    names.sort(key=lambda x : x[0])

    for name in names:
        print(name)
    print(" ")
