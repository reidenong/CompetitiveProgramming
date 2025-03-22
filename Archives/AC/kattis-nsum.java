/*
 * Kattis - nsum
 * sum of n-integers using functional programming.
 */

import java.util.*;
public class nsum {
    public static List < Integer > lst = new ArrayList < > ();
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        int N = scnr.nextInt(), k;
        for (int i = 0; i < N; i++) {
            k = scnr.nextInt();
            lst.add(k);
        }
        System.out.println(lst.stream().reduce(0, (x, y) - > x + y));
    }
}
