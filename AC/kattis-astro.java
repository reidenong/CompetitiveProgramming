/**
 * kattis-astro
 * 
 * - Initial idea to use a boolean array to check if there is a flash at a given
 *   minute where each minute is a boolean in the array quickly shows to be
 *   unideal as we need to find the earliest timing. Representing in an arrau
 *   removes the relative time for each item.
 * 
 * - We instead use a set to represent each distinct flash as a integer, the number
 *   of minutes from saturday 00:00 where the star flashes. Using sets, we are able to
 *   leverage set intersection abilities using set1.retainAll(set2) to find
 *   common flashes, which are denoted by a single number being in both sets.
 * 
 * - We take the minimum number, and translate that into Day-time format
 * 
 * - Note that in choosing the number of days to simulate the flash, 1000 is abit
 *   of an arbitrary number. Choosing smaller numbers does not ensure rigour in 
 *   ensuring that the stars will not flash at a much much later timing.
 *   Perhaps there is some lower bound on the number of days to simulate but
 *   i did not check.
 * 
 * Time: Worst case 1440000 operations
 * Mem: Worst case 1440000 * Mem(integer)
 */
import java.util.*;
public class astro {
    public static Set<Integer> star0 = new HashSet<>();
    public static Set<Integer> star1 = new HashSet<>();
    public static int[] start = new int[2];
    public static int[] interval = new int[2];
    public static String[] days = new String[] {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    public static int HHMMtoInt(String s) {
        String[] timings = s.split(":");
        return Integer.valueOf(timings[0]) * 60 +
               Integer.valueOf(timings[1]);
    }

    public static String timeFormat(String s) {
        if (s.length() == 1) {
            return "0" + s;
        } else {
            return s;
        }
    }

    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        start[0] = HHMMtoInt(scnr.nextLine());
        start[1] = HHMMtoInt(scnr.nextLine());
        interval[0] = HHMMtoInt(scnr.nextLine());
        interval[1] = HHMMtoInt(scnr.nextLine());
        scnr.close();

        // Record star flashings
        for (int i = 0; i < 2; i++) {
            int flash = start[i];
            while (flash/1440 < 1000) {
                if (i == 0) star0.add(flash);
                else star1.add(flash);
                flash += interval[i];
            }
        }

        // Find set intersection
        star0.retainAll(star1);

        // Output answer
        if (star0.size() == 0) {
            System.out.println("Never");
        } else {
            int flash = Collections.min(star0);
            System.out.println(days[(flash/1440)%7]);
            System.out.println(timeFormat((flash%1440)/60 + "") 
                               + ":" + timeFormat(flash%60 + ""));
        }
    }
}
