/**
 * Union Find Disjoint Sets
 * 
 * - Data structure used to model a collection of disjoint sets which can efficiently determine which set an item belongs to
 *  as well as to unite two sets
 * 
 * - code taken from cp-book github, here for easy reference
 * 
 * Time: O(1) operations
 * Space: O(N) 
 */
import java.util.*;
public class Ufds {
    public static class UnionFind {     // OOP style
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
    
    public static void main(String... args) {
        UnionFind uf = new UnionFind(5);
        uf.unionSet(0, 1);
        uf.unionSet(2, 3);
        uf.sizeOfSet(0);              // 2
        uf.isSameSet(1, 3);         // false
    }
}
