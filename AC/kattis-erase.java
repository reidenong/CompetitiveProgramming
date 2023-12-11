/**
 * kattis-erase
 * 
 * - if even swaps, check if data1 == data2
 * 
 * - if odd swaps, swap everything using stream for ease of coding, check.
 * 
 * Time: O(stringLength)
 * Mem: O(1)
 */
import java.util.*;
public class erase {
    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        scnr.nextLine();
        String data1 = scnr.nextLine();
        String data2 = scnr.nextLine();
        scnr.close();

        // Flip data if flips r odd
        String data3;
        if (N % 2 == 0) {
            data3 = data2;
        } else {
            data3 = data2.chars()
                         .mapToObj(x -> (Character) (char) x)
                         .map(x -> Integer.valueOf(x) - 48)
                         .map(x -> 1 - x)
                         .map(x -> Integer.toString(x))
                         .reduce("", (x, y) -> x + y);
        }

        // Check correctedness
        if (data1.equals(data3)) {
            System.out.println("Deletion succeeded");
        } else {
            System.out.println("Deletion failed");
        }
    }
}
