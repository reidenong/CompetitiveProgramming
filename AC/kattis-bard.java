/**
 * kattis-bard
 * 
 * - Generic set problem, bit of a time waster
 * 
 * - Manage all villagers as a list of sets. If bard is there, add new song 
 *   for all villagers. Else if no bard, use unique property of hashset to find
 *   all known songs and redistribute to all present villagers.
 * 
 * Time: O(EN)
 * Mem: O(EN)
 */
import java.util.*;
import java.lang.Math;
public class bard {
    public static List<Set<Integer>> villagers = new ArrayList<>();
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int E = sc.nextInt();
        int songs = 0;

        // Initializing villagers known songs
        for (int i = 0; i < N; i++) {
            villagers.add(new HashSet<Integer>());
        }

        // For each Evening
        List<Integer> people = new ArrayList<>();
        for (int i = 0; i < E; i++) {
            // Registering each person
            boolean bard = false;
            people.clear();
            int numOfPeople = sc.nextInt();
            for (int j = 0; j < numOfPeople; j++) {
                int newPerson = sc.nextInt() - 1;
                if (newPerson == 0) {
                    bard = true;
                }
                people.add(newPerson);
            }

            // Check for Bard
            if (bard) {
                for (int j = 0; j < numOfPeople; j++) {
                    villagers.get(people.get(j)).add(songs);
                }
                songs++;

            // If no bard, redistribute songs
            } else {
                Set<Integer> allSongs = new HashSet<>();
                for (int j = 0; j < numOfPeople; j++) {
                    allSongs.addAll(villagers.get(people.get(j)));
                }
                for (int j = 0; j < numOfPeople; j++) {
                    villagers.get(people.get(j)).addAll(allSongs);
                }
            }
        }
        sc.close();

        // Find villagers who know all songs
        System.out.println(1);
        for (int i = 1; i < N; i++) {
            if (villagers.get(i).size() == songs) {
                System.out.println(i + 1);
            }
        }
    }
}
