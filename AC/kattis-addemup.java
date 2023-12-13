/**
 * kattis-addemup
 * 
 * - Not really a hard problem, the solution is the obvious one of flipping
 *   all numbers and checking for a match.
 * 
 * - We check the numbers on the fly, so that as we receive each number
 *   we check if it can work with any of the previous numbers (including flipped)
 *   and if not we add it to our previous set of flipped numbers.
 * 
 * - We use Set because .contains() method gives us O(1) checking.
 * 
 * Time: O(N)
 * Mem: O(N)
 */
import java.util.*;
public class addemup {
    public static Set<Integer> allCards = new HashSet<>();

    // Helper Method to flip integers
    public static int flip(int x) {
        StringBuilder s = new StringBuilder(String.valueOf(x)).reverse();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '3' || s.charAt(i) == '4' || s.charAt(i) == '7') {
                return 0;
            }
            if (s.charAt(i) == '6') s.setCharAt(i, '9');
            else if (s.charAt(i) == '9') s.setCharAt(i, '6');
        }
        return Integer.valueOf(s.toString());
    }

    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        int S = scnr.nextInt();
        scnr.nextLine();

        // Check for complements for every new number we get on the fly
        String[] cards = scnr.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            int curr = Integer.valueOf(cards[i]);
            int currF = flip(curr);
            if (allCards.contains(S - curr) || 
                allCards.contains(S - currF)) {
                System.out.println("YES");
                System.exit(0);
            }
            allCards.add(curr);
            if (currF != 0) {
                allCards.add(currF);
            }
        }
        System.out.println("NO");
        scnr.close();
    }
}
