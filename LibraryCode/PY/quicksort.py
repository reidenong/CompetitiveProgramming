def swap(a, b) :
    arr[a], arr[b] = arr[b], arr[a]

def quicksort(lo, hi) :
    if lo >= hi :
        return

    # Choose random pivot
    pivot = arr[random.randint(lo, hi)]

    # <x : [lo, i - 1]
    # =x : [i, j - 1]
    # >x : [j, hi]
    i = lo
    j = lo
    k = hi

    while j <= k :
        if arr[j] < pivot :
            swap(i, j)
            i += 1
            j += 1
        elif arr[j] > pivot :
            swap(j, k)
            k -= 1
        else :
            j += 1
                    
    quicksort(lo, i - 1)
    quicksort(j, hi)

# Sort
quicksort(0, len(arr) - 1)
