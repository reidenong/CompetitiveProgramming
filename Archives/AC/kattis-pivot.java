import java.util.*;

public class App {
    static int[] arr = new int[100001];
    static Stack<Integer> ansStack = new Stack<Integer>(); 

    //MAIN
    public static void main(String[] args) throws Exception {

        // Receiving input
        Scanner scnr = new Scanner(System.in);
        int N = scnr.nextInt();
        for(int i = 0; i < N; i++){
            arr[i] = scnr.nextInt();
        }
        scnr.close();

        // Iterate through array, noting the curr Max Integer.
        // If curr idx > Max Integer, add to the answer array
        // At the same time, pop all numbers in the answer stack > currMax
        int maxInt = 0;
        for(int i = 0; i < N; i++){
            while(ansStack.size() != 0 && ansStack.peek() > arr[i]){
                ansStack.pop();
            }

            if(arr[i] > maxInt){
                maxInt = arr[i];
                ansStack.push(arr[i]);
            }
        }
    
        System.out.println(ansStack.size());
    }
}
