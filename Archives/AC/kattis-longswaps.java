/**
 * kattis-longswaps
 * 
 * - Observe that in general, the best way to move a character to its given
 *   spot is to bring it to the left or right edge of the string, then to move it
 *   into its given position. If the character cannot be moved to left/right edge or
 *   its end position is too near to the edges, then it is impossible to be sorted.
 * 
 * - To check if a character can be moved to the left/right edge, we can then check
 *   if its end position is at least k positions away from the left or right.
 *   This shows that any character that is not at least k positions away from the left
 *   or right edge cannot be moved, and also no character can be moved there.
 * 
 * - This implies that any character at those positions must already be correct. Any
 *   other chaarcter can be moved by the above LR-edge method.
 * 
 * - Thus the word is valid if all the unmovable characters are already correct.
 * 
 * Time: O(N log N) for sorting
 * Space: O(N)
 */
import java.util.*;
import java.util.stream.IntStream;
public class longswaps {

    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int N = s.length();
        int k = sc.nextInt();
        
        // Convert word to array of ASCII integers
        int[] word = s.chars().map(x -> x - 97).toArray();
        int[] sorted = Arrays.copyOf(word, N);
        Arrays.sort(sorted);

        // Check if word is valid
        for (int i = 0; i < N; i++) {
            if (i >= N - k &&
                i < k &&
                word[i] != sorted[i]) {
                System.out.println("No");
                return;
                }
        }
        System.out.println("Yes");
        return;   
    }
}
