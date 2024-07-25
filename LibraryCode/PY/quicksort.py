'''
Expected O(N log N) QuickSort with Random pivot and DNF Partitioning (3 way)

- An easier way to reason about the DNF Partitioning is that at any given point, the array is like
    [____<x____ , ___==x___ , ____?___ , ___>x___]
                  i           j         k           

- We move along with idx j.

when arr[j] < pivot, we want to put it to the left of the (==x) portion in the (<x) portion, so
we swap(i, j) and i++ j++, like shifting arr[j] through the (==x) portion 

when arr[j] == pivot, we want to extend the (==x) portion, so we just move on, ie. j++

when arr[j] > pivot, we want to move it to the right portion, so we swap j and k.
take note that since we don't know whats at k, we decrease k after: if the item originally at
k is still larger than pivot, we will need to move it right again, but now it will be at one location 
to the left of its original.

- when j > k, we are done.

'''

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
