/**
 * kattis-electionparadox
 * 
 * - greedily pick the cities with the most votes to lose to.
 * 
 * Time: O(N log N)
 * Mem: O(N)
 */
import java.util.*;
public class electionparadox {
    public static int[] cities = new int[1000];
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();

        // Receiving input
        for (int i = 0; i < N; i++) {
            cities[i] = scnr.nextInt();
        }
        Arrays.sort(cities, 0, N);

        int votes = 0;
        for (int i = 0; i < N; i++) {
            if (i <= N/2) {
                votes += cities[i]/2;
            } else {
                votes += cities[i];
            }
        }
        System.out.println(votes);
        scnr.close();
    }
}
