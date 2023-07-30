/*
 * Kattis - color
 * 
 * Arbitrary Kattis Greedy Problem cuz I'm bored
 * 
 * Can just keep track of the current minimum color and use a new machine 
 * if the color is too different or there is too many clothes in the machine
 * 
 * Time: O(N log N) sorting bottleneck
 * Space: O(N)
 */
import java.util.*;

public class color {
    public static int[] colors = new int [100000];

    public static void main(String[] args) throws Exception {
        Scanner scnr = new Scanner(System.in);
        int S = scnr.nextInt(), C = scnr.nextInt(), K = scnr.nextInt();
        
        // Receiving color input
        for (int i = 0; i < S; i++) colors[i] = scnr.nextInt();
        scnr.close();

        // Sorting the colors
        Arrays.sort(colors, 0, S);

        // Greedy Algorithm
        int machines = 0, inWash = 0, currMin = colors[0];
        for (int i = 0; i < S; i++) {

            // Need to use new machine if color is too different or if machine is full
            if (colors[i] - currMin > K || inWash == C) {
                machines++;
                inWash = 1;
                currMin = colors[i];
            }

            // Use same machine
            else inWash++;
        }

        // Output Machines
        System.out.println(machines + 1);
    }
}
