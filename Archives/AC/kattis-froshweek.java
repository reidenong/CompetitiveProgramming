/**
 * kattis-froshweek
 * 
 * - Deceptively like a bubble sort problem, but it actually requires use
 *   of a merge sort.
 * 
 * - Firstly, the minimum number of sorts is the number of inversion pairs in 
 *   the given sequence. A inversion pair is a pair of indices s.t. i < j and 
 *   arr[i] > arr[j]. 
 * 
 * - Secondly, the naive O(N^2) solution is a nested iteration over the array to
 *   compare every 2 elements. This is too slow for N = 1M elements though.
 * 
 * - We can use merge sort with a slight modification to count the inversion pairs.
 *   This is because when a element in the right subarray is smaller than the
 *   first element in the left subarray, it is then also smaller then every element
 *   in the left subarray, and we can make a easy O(1) call with leftArray.length.
 * 
 * - O(N log N) merge sort is fast enough.
 *
 */
import java.util.*;
public class WS {
    public static int[] arr = new int[1000001];
    public static long count = 0;

    // MergeSort (sort)
    public static void sort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
 
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
 
            merge(arr, left, mid, right);
        }
    }

    // MergeSort (merge)
    public static void merge(int arr[], int left, int mid, int right) {
        int[] L = Arrays.copyOfRange(arr, left, mid + 1);
        int[] R = Arrays.copyOfRange(arr, mid + 1, right + 1);
  
        // Initial indices of left and right subarrays
        int i = 0, j = 0;
 
        // Initial index of total merged array
        int k = left;
        while (i < L.length && j < R.length) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
                count += L.length - i;
            }
            k++;
        }
 
        // Copy remaining elements of L[] if any
        while (i < L.length) {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        // Copy remaining elements of R[] if any
        while (j < R.length) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        for (int i = 0; i < N; i++) arr[i] = scnr.nextInt();
        scnr.close();

        sort(arr, 0, N - 1);

        System.out.println(count);
    }
}
