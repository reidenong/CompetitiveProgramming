/**
 * kattis-metronome
 * 
 *  - Simple question, just remember to convert to double.
 * 
 * Time: O(1)
 * Mem: O(1)
 */
import java.util.*;
public class metronome {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in);
        System.out.println((double)scnr.nextInt()/4);
        scnr.close();
    }
}
