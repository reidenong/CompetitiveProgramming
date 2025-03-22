/**
 * kattis-tenis
 * 
 * - Not finished, too much of a time waster, no learning value.
 * 
 */
import java.util.*;
public class WS {

    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        String[] names = scnr.nextLine().split(" ");
        boolean[] federer = new boolean[]{names[0].equals("federer"), 
                                          names[1].equals("federer")};

        int N = scnr.nextInt();
        for (int i = 0; i < N; i++) {
            String[] matches = scnr.nextLine().split(" ");
            boolean valid = true;
            
            int leftWins = 0;
            for (String match : matches) {
                String[] splitMatch = match.split(":");
                int left = Integer.valueOf(splitMatch[0]);
                int right = Integer.valueOf(splitMatch[1]);

                // Checking and found Set is not valid
                if (Math.abs(left - right) < 2 && left != 6 && right != 6) {
                    valid = false;
                    break;
                }
                if (left < 6 && right < 6) {
                    valid = false;
                    break;
                }
                // Federer checks
            }

            // Checking and found match is not valid

            if (valid) {
                System.out.println("da");
            } else {
                System.out.println("ne");
            }
            
        }

    }
}
