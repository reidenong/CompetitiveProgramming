/**
 * kattis-internationaldates
 * 
 * - trivial
 * 
 * Time: O(1)
 * Mem: O(1)
 */
import java.util.*;
public class internationaldates {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        String[] date = scnr.nextLine().split("/");

        int AA = Integer.valueOf(date[0]);
        int BB = Integer.valueOf(date[1]);

        if (AA <= 12 && BB <= 12) {
            System.out.println("either");
        } else if (AA > 12) {
            System.out.println("EU");
        } else {
            System.out.println("US");
        }

        scnr.close();
    }
}
