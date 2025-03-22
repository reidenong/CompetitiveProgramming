/**
 * kattis-coffeecupcombo
 *
 * - refill to 3, so after using one you can bring over 2.
 * 
 * Time: O(N)
 * Mem: O(1)
 */
import java.util.*;
public class coffeecupcombo {
    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt(); 
        scnr.nextLine();
        String schedule = scnr.nextLine();

        // Iterate through lectures
        int coffee = 0, lectures = 0;
        for (int i = 0; i < N; i++) {         
            if (schedule.charAt(i) == '1') {  // Refill to 3
                coffee = 3;
            }
            if (coffee > 0) {                 // uses a coffee
                coffee--;
                lectures++;
            }
        }
        System.out.println(lectures);
        scnr.close();
    }
}
