import java.util.*;

public class App {
    public static int[][] letterFreq = new int[2][27];

    static int asciiRep(char x){
        int ascii = ((int) x)-65;
        return ascii;
    }

    //MAIN
    public static void main(String[] args) throws Exception {

        // Receiving input
        Scanner scnr = new Scanner(System.in);
        int N = scnr.nextInt();
        String code = scnr.next();
        String guess = scnr.next();

        char[] codeChars = code.toCharArray();
        char[] guessChars = guess.toCharArray();

        int r = 0, s = 0;

        // Iterate through all letters in code(0) & guess(1)
        for(int i = 0; i < N; i++){
            // Count r
            if(codeChars[i] == guessChars[i]) r++;

            // Convert characters to ASCII, log frequency in array
            letterFreq[0][asciiRep(codeChars[i])]++;
            letterFreq[1][asciiRep(guessChars[i])]++;
        }

        // Check frequency of letters, take min
        for(int i = 0; i < 26; i++){
            s += Math.min(letterFreq[0][i], letterFreq[1][i]);
        }

        System.out.println(r + " " + (s-r));

    scnr.close();
    }
}
