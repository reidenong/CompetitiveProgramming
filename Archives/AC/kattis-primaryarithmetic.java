/*
 * Kattis - primaryarithmetic
 * 
 * Used Java just to brush up on syntax, python would be much more
 * suitable for this task given small input sizes as well as 
 * easy conversion between data types and reversing lists
 * 
 */
import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scnr = new Scanner(System.in);

        // For each Testcase
        while(true){
            // Receiving input 
            String N = scnr.next(), M = scnr.next();

            // End criterion
            if(N.equals("0") && M.equals("0"))break;

            // Pad with Zeros to length 21, 
            // convert to char array and reverse
            int endLen = 25;
            N = "0".repeat(endLen - N.length()) + N;
            M = "0".repeat(endLen - M.length()) + M;
            char[] Nchar = N.toCharArray();
            char[] Mchar = M.toCharArray();

            // Carry out addition, count carries in reverse
            int carries = 0, addOn = 0;
            for(int i = endLen-1; i > 0; i--){
                if((Character.getNumericValue(Nchar[i]) + Character.getNumericValue(Mchar[i]) + addOn) > 9){
                    carries++;
                    addOn = 1;
                }else addOn = 0;
            }

            // Display results
            if(carries == 0)System.out.println("No carry operation.");
            else if(carries == 1)System.out.println("1 carry operation.");
            else System.out.println(carries + " carry operations.");
        }
    scnr.close();
    }
}
