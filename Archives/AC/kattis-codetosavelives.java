/**
 * kattis-codetosavelives
 * 
 * - Simple question, more of a test of java regex abilities.
 * 
 * - Stream is used to concisely add spaces to all the characters.
 * 
 * Time: O(N)
 * Mem: O(1)
 */
import java.util.*;
import java.util.stream.*; 
public class codetosavelives {
    public static void main(String... args) {
        Scanner scnr = new Scanner(System.in); 
        int N = scnr.nextInt(); 
        scnr.nextLine();

        for (int i = 0; i < N; i++) {
            String s1 = scnr.nextLine()
                            .replaceAll("\\s", "");
            String s2 = scnr.nextLine()
                            .replaceAll("\\s", "");
            String result = String.valueOf(Integer.valueOf(s1) + Integer.valueOf(s2));
            
            System.out.println(
                result.chars().mapToObj(x -> (Character) (char) x)
                    .map(x -> String.valueOf(x) + " ")
                    .reduce((x, y) -> x + y)
                    .get()
            );
        }
        scnr.close();
    }
}
