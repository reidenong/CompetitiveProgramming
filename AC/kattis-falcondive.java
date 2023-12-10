/**
 * kattis-falcondive
 * 
 * - Fairly straightforward but tedious question.
 * 
 * - Firstly we reference all chars to a grid of integers for easier logic
 * 
 * - next to find the background of the result image, superimpose img1 and img 2
 *   but only consider all non falcon images
 * 
 * - Lastly to find the relative offset for falcon, just search for the top left most
 *   falcon in both img1 and img2. Their relative positioning is the same as the 
 *   relative postiioning in img2 and result. just find the offset and apply to img2.
 * 
 * Time: O(N*M)
 * Mem: O(N*M)
 */
import java.util.*;
public class falcondive {
    public static int[][] img1 = new int[1001][1001];
    public static int[][] img2 = new int[1001][1001];
    public static int[][] result = new int[1001][1001];
    public static int[] offset = new int[]{-1, -1};

    public static void main(String... args) {
        // Receiving input
        Scanner scnr = new Scanner(System.in); 
        int rows = scnr.nextInt();
        int cols = scnr.nextInt();
        int target = Integer.valueOf(scnr.nextLine().charAt(2));
        for (int i = 0; i < rows; i++) {
            String currRow = scnr.nextLine();
            for (int j = 0; j < cols; j++) {
                img1[i][j] = Integer.valueOf(currRow.charAt(j));
                //System.out.println(img1[i][j]);
            }
        }
        scnr.nextLine();
        for (int i = 0; i < rows; i++) {
            String currRow = scnr.nextLine();
            for (int j = 0; j < cols; j++) {
                img2[i][j] = Integer.valueOf(currRow.charAt(j));
                //System.out.println(img2[i][j]);
            }
        }
        scnr.close();

        // Creating final background, find offset
        int[][] refPoint = new int[2][2];
        boolean found1 = false, found2 = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (img1[i][j] != target) result[i][j] = img1[i][j];
                else result[i][j] = img2[i][j];

                if (!found1 && img1[i][j] == target) {
                    refPoint[0][0] = i; refPoint[0][1] = j;
                    found1 = true;
                }
                if (!found2 && img2[i][j] == target) {
                    refPoint[1][0] = i; refPoint[1][1] = j;
                    found2 = true;
                }
            }
        }

        // Find offset, apply offset to img2 targets
        int rowOffset = refPoint[1][0] - refPoint[0][0];
        int colOffset = refPoint[1][1] - refPoint[0][1];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (img2[i][j] == target &&
                    (i + rowOffset < rows && i + rowOffset >= 0) &&
                    (j + colOffset <= cols && j + colOffset >= 0)) {
                    result[i + rowOffset][j + colOffset] = target;
                }
            }
        }

        // Print result
        for (int i = 0; i < rows; i++) {
            String currRow = "";
            for (int j = 0; j < cols; j++) {
                currRow += String.valueOf((char) result[i][j]);
            }
            System.out.println(currRow);
        }
    }
}
