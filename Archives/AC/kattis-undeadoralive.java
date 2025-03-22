/**
 * kattis-undeadoralive
 * 
 * - trivial
 * 
 * Time: O(1)
 * Mem: O(1)
 */
import java.util.*;
public class undeadoralive {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        String text = scnr.nextLine();

        if (text.contains(":)") && text.contains(":(")) {
            System.out.println("double agent");
        } else if (text.contains(":)")) {
            System.out.println("alive");
        } else if (text.contains(":(")) {
            System.out.println("undead");
        } else {
            System.out.println("machine");
        }
        scnr.close();
    }
}
