import java.util.*;

public class App {
    static ArrayList<Integer> arrLis = new ArrayList<Integer>();

    //MAIN
    public static void main(String[] args) throws Exception {

        // Receiving input
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        int prevInt = s.nextInt(), nextInt;
        arrLis.add(prevInt);
        for(int i = 0; i < N-1; i++){
            nextInt = s.nextInt();
            if(nextInt > prevInt){
                arrLis.add(nextInt);
                prevInt = nextInt;
            }
        }
        s.close();
        System.out.println(arrLis.size());
        System.out.println(arrLis.toString().replace("[","").replace("]","").replace(",",""));
    }
}
