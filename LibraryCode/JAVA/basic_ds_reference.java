import java.util.*;

public class App {
    // Classic Global Array of Integers
    static int[] arr = new int[101];
  
    // ArrayList, basically a vector
    static ArrayList<Integer> arrLis = new ArrayList<Integer>();
    arrLis.add(100);        // Append items to back 
    arrLis.get(0);          // Reference by index
    arrLis.set(0, 200);     // Modify an element, refer to index
    arrLis.remove(0);       // Remove element by index
    
    Collections.sort(arrLis);               // Sorting
    int arrLisSize = arrLis.size();         // Get size of arrayList
    System.out.println(arrLis.toString());  // Print arrayList
    System.out.println(arrLis.toString().replace("[","").replace("]","").replace(",",""));
    // (Printing arrayList with no brackets, commas)
    
}
