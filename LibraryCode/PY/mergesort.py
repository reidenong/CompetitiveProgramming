'''
Merge Sort

- uses divide and conquer to repeatedly split the array into half 
  before sorting the halves and merging them back together.

- extra uses include being able to count the number of inversion pairs more
   efficiently in O(N log N) time.

- Merge sort algorithm has 2 components :
    sort will sort all the elements in a given range
    merge merges 2 given range together

Time: O(N log N)
Mem: O(N)
'''
# Receiving input
N = int(input())
arr = [int(x) for x in input().split()]
'''
Sample input:

5
3 2 4 1 5
'''
inversionCount = 0

# MERGESORT sort
def ms_sort(arr, left, right) :
    # base case
    if not left < right : return 

    middle = left + (right - left) // 2

    ms_sort(arr, left, middle)
    ms_sort(arr, middle + 1, right)

    ms_merge(arr, left, middle, right)

# MERGESORT merge
def ms_merge(arr, left, middle, right) :
    leftArr = arr[left : middle + 1]
    rightArr = arr[middle + 1 : right + 1]

    l, r, k = 0, 0, left
    leftBound, rightBound =  len(leftArr), len(rightArr)
    while (l < leftBound and r < rightBound) :
        if leftArr[l] < rightArr[r] :
            arr[k] = leftArr[l]
            k += 1
            l += 1
        else :
            global inversionCount
            inversionCount += leftBound - l
            arr[k] = rightArr[r]
            k += 1
            r += 1
    
    while (l < leftBound) :
        arr[k] = leftArr[l]
        k += 1
        l += 1
    while (r < rightBound) :
        arr[k] = rightArr[r]
        k += 1
        r += 1

ms_sort(arr, 0, N - 1)
print (inversionCount) 
