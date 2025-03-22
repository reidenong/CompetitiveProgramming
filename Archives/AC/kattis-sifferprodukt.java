/**
 * kattis-sifferprodukt
 * 
 * - Recursively find the digit product until satisfiable. 
 *
 * - Stream is used to concisely find the digit product.
 * 
 * Time: O(N*iterations) (no quick way to find number of iterations)
 * Mem: O(N)
 */
import java.util.*;
public class sifferprodukt {
    public static int product(int i) {
        if (i < 10) return i;
        
        return product(
               String.valueOf(i).chars()
                     .map(x -> Integer.valueOf(x) - 48)
                     .filter(x -> x != 0)
                     .reduce(1, (x, y) -> x * y)
                );
    }
  
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt();
        System.out.println(product(N));
        scnr.close();
    }
}
