/*
kattis-pagelayout

Key considerations
- with N <= 20, testcase <= 500, naive bit mask results in 1000^2 * 
  2^20 * 500 = ~1e14 will DEFINITELY TLE.
- Use of generative with filters is thus the way, where at each step if 
  overlap criterion is not met further such combinations are not generated


Time: O(2^N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

// Data strctures
vector<tuple<int, int, int, int>> stories;  // Storing story infomation
int area[21];                               // Storing areas of stories
bool useStory[21];                          // Show if story in use
int N, maxArea = 0;     

// Function to test if two stories overlap
bool overlap (int idxA, int idxB) {
    // Defining rectangles [x1, x2, y1, y2]
    int A[4] = { get<2>(stories[idxA]),
                 get<2>(stories[idxA]) + get<0>(stories[idxA]),
                 get<3>(stories[idxA]),
                 get<3>(stories[idxA]) + get<1>(stories[idxA])
                };
    int B[4] = { get<2>(stories[idxB]),
                 get<2>(stories[idxB]) + get<0>(stories[idxB]),
                 get<3>(stories[idxB]),
                 get<3>(stories[idxB]) + get<1>(stories[idxB])
                };

    // Checking if A, B overlaps
    bool xOverlap = true, yOverlap = true;
    if ((A[1] <= B[0] && A[0] < B[0]) ||
        (B[1] <= A[0] && B[0] < A[0])) {
            xOverlap = false;
        }
    if ((A[2] >= B[3] && A[3] > B[3]) ||
        (B[2] >= A[3] && B[3] > A[3])) {
            yOverlap = false;
        }
    
    // Return overlap
    if (xOverlap && yOverlap) return true;
    else return false;
}

// Combinatoric recursive backtracking
void backtrack (int curr, int currArea) {

    // End of story index
    if (curr == N) {
        return;
    }

    // Dont use story [curr]
    backtrack(curr + 1, currArea);

    // Test if curr overlaps with any existing rectangle
    for (int i = 0; i < N; i++) {
        if (useStory[i]) {
            if (overlap(curr, i)) {
                return;
            }
        }
    }

    // Use story [curr]
    useStory[curr] = 1;
    if (currArea + area[curr] > maxArea) {  // Update new area with story [curr]
        maxArea = currArea + area[curr];
    }
    backtrack(curr + 1, currArea + area[curr]);
    useStory[curr] = 0;
}

// MAIN
int main () {
    int W, H, X, Y;

    // For each testcase
    while (cin >> N) {
        if (N == 0) break;

        // Resetting data structures
        maxArea = 0;
        while (!stories.empty()) stories.pop_back();
        memset(useStory, 0, sizeof(useStory));

        // Receiving story input
        for (int i = 0; i < N; i++) {
            cin >> W >> H >> X >> Y;

            // Calculate area, add to array
            area[i] = W*H;

            // Add story to stories
            stories.push_back(make_tuple(W, H, X, Y));
        }

        // Recursive backtrack
        backtrack(0, 0);
        cout << maxArea << endl;
    }
}
