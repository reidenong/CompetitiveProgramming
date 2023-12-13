/**
 * Merge Sort Algorithm in O(N log N)
 *   - with optional inversion pair counter -
 * 
 * - merge sort is a algorithm that uses divide and conquer to split the array up into halves again
 *   and again, then it merges each sorted half until the full sorted array is returned.
 *
 * - intuitively, the reduction in time over O(N^2) algorithms such as bubble sort can be attributed by 
 *   how in the merging component of merge sort, since both halves are already sorted, we only need to compare 
 *   the first two elements of each subarray instead of N^2 comparisons.
 *
 * - This code snippet also includes a use of merge sort in counting the number of inversion pairs in the arr,
 *   but this can be easily commented out if it is not required. 
 *
 * Time: O(N log N)
 * Mem: O(N)
 */
import java.util.*;
public class MergeSort {
    public static int[] arr = new int[10];   // Array to sort
    public static long count = 0;            // Inversion pair counter

    // Sorting component of merge sort.
    public static void sort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left)/2;
 
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
 
            merge(arr, left, mid, right);
        }
    }

    // Merging component of merge sort
    public static void merge(int arr[], int left, int mid, int right) {
        int[] L = Arrays.copyOfRange(arr, left, mid + 1);
        int[] R = Arrays.copyOfRange(arr, mid + 1, right + 1);
  
        int i = 0;          // Starting index of left subarray
        int j = 0;          // Staring index of right subarray
        int k = left;       // Starting index of merged subarray
        while (i < L.length && j < R.length) {
            if (L[i] <= R[j]) {         // Use first element of left subarray
                arr[k] = L[i];
                i++;
            } else {                    // Use first element of right subarray
                arr[k] = R[j];
                j++;
                count += L.length - i;  // Counting inversion pairs
            }
            k++;
        }
 
        // Copy remaining elements of L[], R[] if any
        while (i < L.length) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < R.length) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Driver function to test functionality
    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        for (int i = 0; i < N; i++) 
            arr[i] = scnr.nextInt();
        scnr.close();

        // Merge Sort array (mutates arr directly)
        sort(arr, 0, N - 1);
        
        System.out.println(count);
    }
}
