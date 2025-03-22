/**
 * kattis-avoidland
 * 
 * - We begin with a few observations critical to the solution:
 *     1. As long as we solve the rows to have at most one pawn per row and the 
 *        cols to have one pawn per row, the solution is optimal as there is no
 *        diagonal movement
 * 
 *     2. For minimal number of moves, we always move the nearest pawn to the nearest gap
 *        ie. for OXXO -> XXOO, move the first X to the first O and the second X to the second O is
 *        as good as moving second X to first O.
 * 
 * - Now for implementation, we use a greedy approach to settle rows and columns independently as
 *   stated in the first observation.
 * 
 * - Initial approach was to use a priorityQueue to store the postions of pawns, then for i in N add the
 *   absolute difference of the position of the ith pawn and the ith gap to the total moves. However, this 
 *   too slow and solution TLEs with O(NlogN) time complexity.
 * 
 * - We can do better by using a "pawn debt" system. When we are lacking a pawn at row i, the pawn debt is
 *   registered as -1, and when we have a extra pawn at row i, the pawn debt is registered as +1. Observe that now 
 *   for moving from row i to row i+1, the number of moves is equivalent to the abs(pawn_debt) as the pawn debt 
 *   registers a difference in pawns and each diff will account for a move of 1.
 * 
 * Time: O(N) 
 * Mem: O(N)
 */
import java.util.*;
import java.lang.Math;
public class avoidland {
    public static int[] row = new int[1000001];
    public static int[] col = new int[1000001];
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);

        // Receiving input
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int r = sc.nextInt() - 1;
            int c = sc.nextInt() - 1;
            row[r]++;
            col[c]++;
        }
        sc.close();

        // Greedy approach, for each lane register the pawn debt and add to total moves
        long moves = 0;
        int carryRow = 0, carryCol = 0;
        for (int i = 0; i < N; i++) {
            carryRow += row[i] - 1;
            carryCol += col[i] - 1;
            
            moves += Math.abs(carryRow) + Math.abs(carryCol);
        }

        // Output answer
        System.out.println(moves);
    }
}
