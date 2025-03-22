/*
 * Kattis - throwns
 * 
 * used java just to brush up.
 * 
 * - Use a stack to keep track of instruction log
 * - for undoing x operations, pop stack x times
 * - useful to use modulo on every throw operation so k*n throws are
 * accurately registered as no throws
 * 
 * Time: O(n)
 * Space: O(n)
 */
import java.util.*;

public class App {
    static Stack<Integer> stack = new Stack<Integer>();

    public static void main(String[] args) throws Exception {
        Scanner scnr = new Scanner(System.in);
        int N = scnr.nextInt(), K = scnr.nextInt();

        // Processing each instruction
        for(int i = 0; i < K; i++){
            String instruction = scnr.next();

            
            // undo action
            if(instruction.equals("undo")){
                int undoX = scnr.nextInt();
                for(int j = 0; j < undoX; j++)stack.pop();

            // regular throws
            }else{
                int throwsX = Integer.parseInt(instruction);
                if(throwsX < 0){    
                    //   anticlockwise
                    stack.push(-1*((-1*throwsX)%N));
                }else{              
                    //clockwise
                    stack.push(throwsX%N);
                }
            }
        }
        scnr.close();

        int result = 0;
        while(!stack.empty()){
            result += stack.pop();
            result %= N;
        }
        if(result < 0){
            result += N;
        }
        System.out.println(result);
    }
}
