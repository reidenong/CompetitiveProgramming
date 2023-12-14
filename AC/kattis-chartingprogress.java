/**
 * kattis-chartingprogress
 * 
 * - easy question, but always irritating to deal with strings esp in java so we 
 *   use stringbuilder.
 * 
 * - we realise we can process each line on the fly, so dont need to store anything.
 * 
 * Time: O(numberOfChars)
 * Mem: O(1)
 */
import java.util.*;
public class chartingprogress {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in);
        int ctr = 0;
        while (true) {
            // Receiving input
            String line;
            try {
                line = scnr.nextLine();
            } catch (NoSuchElementException e) {
                break;
            }
            int n = line.length();

            // New line case
            if (n == 0) {
                ctr = 0;
                System.out.println();
                continue;
            }

            // Count asterisks in line
            int asterisks = 0;
            for (int i = 0; i < n; i++) {
                if (line.charAt(i) == '*') asterisks++;
            }
            String ask = ".";
            StringBuilder newLine = new StringBuilder();
            newLine.append(ask.repeat(n));

            // Edit the StringBuilder
            for (int i = 0; i < asterisks; i++) {
                newLine.setCharAt(n - ctr - 1, '*');
                ctr++;
            }

            // Display final string
            System.out.println(newLine.toString());
        }
    }
}
