/**
 * kattis-bokhyllor
 * 
 * - slightly tricky question.
 * 
 * - We use a greedy method to consistently pick the "hardest" to fit
 *   books, ie. the largest. Since the books will eventually have to go 
 *   into some shelf, we keep picking the biggest books possible that can
 *   fit, and let the smaller books fill in later
 * 
 * - The issue arises when we have a vacancy of 4. By greedy methodology
 *   we will choose a size 3. This is not ok if we have 2 2s and not a 1, as with a 3 we
 *   will have a underutilised space of 1. eg. (0 4 2; 7).
 * 
 * - Accomodate the case by picking 2 2s everytime we have a remaining gap
 *   of 4 and we r good to go.
 * 
 * Time: O(N), where N is the number of books
 * Mem: O(1)
 */
import java.util.*;
public class bokhyllor {
    public static int[] books = new int[3];
    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        for (int i = 0; i < 3; i++) books[i] = scnr.nextInt();
        int width;
        width = scnr.nextInt();
        scnr.close();

        // Repeatedly add the largest possible book
        long shelves = 0;
        while (books[0] + books[1] + books[2] > 0) {  // For each shelf
            shelves++;
            int space = width;
            for (int i = 2; i >= 0; i--) {
                while (space >= (i + 1) && books[i] > 0) {

                    // Edge case: If space is 4, use 2 2s instead of a 3.
                    if (space == 4 && books[1] >= 2) {
                        books[1] -= 2;
                        space -= 4;
                        continue;
                    }

                    // Add a book.
                    space -= (i + 1);
                    books[i]--; 
                }
            }
        }
        System.out.println(shelves);
    }
}
