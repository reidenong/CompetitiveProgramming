/**
 * kattis-rankproblem
 * 
 * - More of a problem with processing input
 * 
 * - With relatively small bounds (n,m < 100) we can just do exactly as the program
 *   says to do. Our time complexity of O(M*N) can easily pass the requirements as it only
 *   has a maximum of 10k operations.
 * 
 *  Time: O(N*M)
 *  Mem: O(N)
 */
import java.util.*;
public class rankproblem {
    public static int[] ranking = new int[101];
    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        int M = scnr.nextInt();
        
        // Initialize starting rankings
        for (int i = 0; i < N; i++) ranking[i] = i + 1;

        // Update for each action
        scnr.nextLine();
        for (int z = 0; z < M; z++) {
            String[] updates = scnr.nextLine().split(" ");
            int winner = Integer.valueOf(updates[0].substring(1));
            int loser = Integer.valueOf(updates[1].substring(1));
            
            // Find winner and loser indexes
            int winnerIdx = 0, loserIdx = 0;
            for (int j = 0; j < N; j++) {
                if (ranking[j] == winner) winnerIdx = j;
                if (ranking[j] == loser) loserIdx = j;
            }

            // Update rankings
            if (winnerIdx > loserIdx) {
                for (int i = loserIdx; i <= winnerIdx; i++) {
                    ranking[i] = ranking[i + 1];
                }
                ranking[winnerIdx] = loser;
            }
            
        }
        scnr.close();
      
        // Print final ranking
        String result = "";
        for (int i = 0; i < N; i++) 
            result += "T" + String.valueOf(ranking[i]) + " ";
        System.out.println(result);
    }
}
