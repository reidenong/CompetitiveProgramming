'''
kattis-ultraquicksort

 - The trick to counting the number of swaps for a bubble sort is not to simulate
   bubble sort as O(N^2) time complexity is too slow. Instead, we use
   merge sort as the O(N log N) complexity is fast enough.

 - The minimum number of swaps is given by the number of inversion pairs in the sequence.

 - in counting the number of inversion pairs, we can do a merge sort, but we modify
   the merge function such that if a element on the right array is smaller than
   a element on the left array, we then have a situation where this is a inversion pair,
   along with every other element on the left array as the left array alr sorted.

 - Note that we cant use python List::pop(0) as pop is O(N)

Time: O(N log N)
Mem: O(N)
'''
# Receiving input
N = int(input())
arr = []
for i in range (N) :
    arr.append(int(input()))
inversionCount = 0

# MERGE SORT 
def ms_sort(arr, left, right) :
    # base case
    if not left < right : return 

    middle = left + (right - left) // 2

    ms_sort(arr, left, middle)
    ms_sort(arr, middle + 1, right)

    ms_merge(arr, left, middle, right)

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
