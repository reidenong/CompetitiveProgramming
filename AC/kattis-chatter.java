/**
 * kattis-chatter
 * 
 *  - Fairly straightforward UFDS problem, but with slightly tricky implementation.
 * 
 *  - It should be fairly obvious that we need to use UFDS to model the groupings of each people.
 * 
 *  - However, in order to get the frequency of each group size, we cannot simply just iterate through each person
 *    and query its group size as this is too slow.
 * 
 *  - Instead, we use a Map to store the frequency of each group size. This way, we can easily update the frequency
 *    of each group size when we merge two groups together, as when we merge 2 groups together we can query the size of
 *    each constituent group before merging. O(1) insertions and deletions are fast enough given the large number of 
 *    updates
 * 
 * Time: O(N log N)
 * Mem: O(N)
 */
import java.util.*;
public class chatter {
    public static class UnionFind {                                              // OOP style
        private ArrayList<Integer> p, rank, setSize;
        private int numSets;
      
        public UnionFind(int N) {
          p = new ArrayList<>(N);
          rank = new ArrayList<>(N);
          setSize = new ArrayList<>(N);
          numSets = N;
          for (int i = 0; i < N; i++) {
            p.add(i);
            rank.add(0);
            setSize.add(1);
          }
        }
      
        public int findSet(int i) { 
          if (p.get(i) == i) return i;
          else {
            int ret = findSet(p.get(i)); p.set(i, ret);
            return ret; } }
      
        public Boolean isSameSet(int i, int j) { return findSet(i) == findSet(j); }
      
        public void unionSet(int i, int j) { 
          if (!isSameSet(i, j)) { numSets--; 
          int x = findSet(i), y = findSet(j);
          // rank is used to keep the tree short
          if (rank.get(x) > rank.get(y)) { p.set(y, x); setSize.set(x, setSize.get(x) + setSize.get(y)); }
          else                           { p.set(x, y); setSize.set(y, setSize.get(y) + setSize.get(x));
                                           if (rank.get(x) == rank.get(y)) rank.set(y, rank.get(y) + 1); } } }
        public int numDisjointSets() { return numSets; }
        public int sizeOfSet(int i) { return setSize.get(findSet(i)); }
    }
    
    public static Map<Integer, Integer> freq = new HashMap<>();                 // K, V -> group size, frequency

    public static int N, R, A, B, C;

    public static int getRandom() {
        R = ((R * A) + B) % C;
        return R;
    }

    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);

        // For each testcase
        while (true) {
            // Receiving input or terminating
            try {
                N = sc.nextInt();
                R = sc.nextInt();
                A = sc.nextInt();
                B = sc.nextInt();
                C = sc.nextInt();
            } catch (Exception e) {
                break;
            }

            // Initialize DSes
            UnionFind uf = new UnionFind(N);
            freq.clear();
            freq.put(1, N);

            // Simulate chattings and meetings
            int x, y;
            int sizeX, sizeY;
            for (int i = 0; i < N; i++) {
                do {
                    x = getRandom() % N;
                    y = getRandom() % N;
                } while (x == y);

                if (uf.isSameSet(x, y)) continue;

                // Decrease frequency of previous group
                sizeX = uf.sizeOfSet(x);
                if (freq.get(sizeX) == 1) freq.remove(sizeX);
                else freq.put(sizeX, freq.get(sizeX) - 1);

                sizeY = uf.sizeOfSet(y);
                if (freq.get(sizeY) == 1) freq.remove(sizeY);
                else freq.put(sizeY, freq.get(sizeY) - 1);

                // Add new big group
                freq.put(sizeX + sizeY, freq.getOrDefault(sizeX + sizeY, 0) + 1);
                uf.unionSet(x, y);
            }

            // Displaying groupings
            System.out.print(uf.numDisjointSets() + " ");
            List<Integer> sizes = new ArrayList<>(freq.keySet());
            Collections.sort(sizes, Collections.reverseOrder());
            for (int size : sizes) {
                int S = freq.get(size);
                if (S == 1) System.out.print(size + " ");
                else System.out.print(size + "x" + S + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
