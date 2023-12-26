/**
 * kattis-reversebinary
 * 
 *  - we use stack to maintain the binary representation of N as the FILO 
 *    structure allows for easy reversal of the string with O(1) operations.
 * 
 *  - we use booleans for a more lightweight representation as N can get kinda
 *    big (1B)
 * 
 *  - remember to typecast back to int as Math::pow() works with doubles.
 */
import java.util.*;
import java.lang.Math;
public class reversebinary {
    public static Stack<Boolean> stk = new Stack<>();
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        while (N > 0) {
            stk.push(N % 2 == 1);
            N /= 2;
        }

        double ans = 0, ctr = 0;
        while (!stk.empty()) {
            if (stk.pop()) {
                ans += Math.pow(2, ctr);
            }
            ctr++;
        }
        System.out.println((int) ans);
        sc.close();
    }
}
