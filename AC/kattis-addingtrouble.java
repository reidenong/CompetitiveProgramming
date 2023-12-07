/**
 * kattis-addingtrouble
 * 
 * - trivial question, remember to use long to prevent overflow
 * 
 * Time: O(1)
 * Mem: O(1)
 */
import java.util.*;
public class addingtrouble {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        long A = scnr.nextLong(); 
        long B = scnr.nextLong();
        long C = scnr.nextLong();
        if ((A + B) == C) {
            System.out.println("correct!");
        } else {
            System.out.println("wrong!");
        }
        scnr.close();
    }
}
