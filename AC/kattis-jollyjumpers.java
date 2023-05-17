import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);

        while(s.hasNextInt()) {
            // Scanning input
            int N = s.nextInt();
            
            // Initialising bool array
            Boolean[] boolArray = new Boolean[N];
            Arrays.fill(boolArray, Boolean.FALSE);
            boolArray[0] = true;

            int prevInt = s.nextInt();
            for(int i = 0; i < N-1; i++){
                int nextInt = s.nextInt();
                int diff = Math.abs(nextInt - prevInt);
                
                // Updating most recent difference
                if(diff < N){
                    boolArray[diff] = true;
                }

                // System.out.println(diff + " " + Arrays.toString(boolArray));

                prevInt = nextInt;
            }

            Boolean jolly = true;
            for(int i = 0 ;i < N; i++){
                if(!(boolArray[i])){
                    jolly = false;
                }
            }

            if(jolly){
                System.out.println("Jolly");
            }else{
                System.out.println("Not Jolly");
            }
        }

        s.close();
    }
}
