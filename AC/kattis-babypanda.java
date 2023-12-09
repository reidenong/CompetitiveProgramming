/**
 * kattis-babypanda
 *
 * - Observe that M is of the form 2^a + 2^b + 2^c +... where a,b,c...
 *   are all +ve integers >= 1 (given M even)
 *  
 * - By dividing M repeatedly by 2, every time we get a odd number, it means
 *   one of the slimes has reached its "birth", and we remove it and
 *   then repeat the process
 * 
 * Time: O(log_2 M)
 * Mem: O(1)
 */
import java.util.*;
import java.lang.Math;
public class babypanda {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        long N = scnr.nextLong();
        long M = scnr.nextLong();
        scnr.close();

        long sneezes = 0;
        while (M != 0) {
            M /= 2;

            if(M % 2 == 1) {
                M--;
                sneezes++;
            }
        }
        System.out.println(sneezes);
    }
}
