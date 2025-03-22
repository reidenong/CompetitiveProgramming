import java.util.*;

public class App {
    // Declaring global array
    static int[] arr = new int[1000001];
    static int N = 0;

    // Simulate shooting balloon at given height
    static int shootBalloon(int arrowHeight){
        int numShot = 0;
        for(int i = 0; i < N; i++){
            // Balloon Popped
            if(arrowHeight == 0){
                break;
            }

            if(arr[i] == arrowHeight){
                //System.out.println(arr[i]);
                arr[i] = 0;
                numShot++;
                arrowHeight--;
            }
        }
        //System.out.println(numShot);
        return numShot;
    }

    // Find leftmost balloon, returns height
    static int findBalloon(){
        for(int i = 0; i < N; i++){
            if(arr[i] > 0){
                return arr[i];
            }
        }
        return 0;
    }

    //MAIN
    public static void main(String[] args) throws Exception {

        // Receiving input
        Scanner s = new Scanner(System.in);
        N = s.nextInt();
        for(int i = 0; i < N; i++){
            arr[i] = s.nextInt();
        }
        s.close();

        // Simulate Firing Arrows
        // Keep firing arrows at any leftmost balloon
        int numPopped = 0, totalShots = 0;

        // Keep firing while not all balloons popped
        while(numPopped < N){
            int currTarget = findBalloon();

            if(currTarget == 0){
                break;
            }

            //System.out.println(currTarget);
            int numShot = shootBalloon(currTarget);
            totalShots++;
            numPopped += numShot;
        }
        //System.out.println(Arrays.toString(arr));
        //System.out.println(numPopped);
        System.out.println(totalShots);
    }
}
