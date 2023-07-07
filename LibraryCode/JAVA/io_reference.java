import java.util.*;

public class App {

    // Scanner Class
    // Fast implementation, Slow deployment
    // Receiving input
    Scanner s = new Scanner(System.in);

    // Receiving whitespace delimited input
    // input: "ABC DEF" >> received: "ABC"
    String spaced_input = s.next();

    // Receiving newline delimited input
    s.useDelimiter(System.getProperty("line.separator"));
    String newline_input = s.next();

    // Closing scanner to free up resources
    s.close();

    
    
    
    //======================================================



    // FastReader class for Fast IO
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
        String next(){
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
  
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble(){
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
  
    public static void main(String[] args){
        FastReader s = new FastReader();
        int n = s.nextInt();
        int k = s.nextInt();
        int count = 0;
        while (n-- > 0) {
            int x = s.nextInt();
            if (x % k == 0)
                count++;
        }
        System.out.println(count);
    }
}
