#include <bits/stdc++.h>
using namespace std;

int level_stars(int level){
    if(level < 11){
        return(5);
    }else if(level < 16){
        return(4);
    }else if(level < 21){
        return(3);
    }else{
        return (2);
    }
}

int main(){
    // Receiving Input
    string history;
    getline(cin, history);
    int N = history.size();

    // Iterating through matches
    int streak = 0;     // Monitors 3W +1 streak bonus
    int rank = 25;      // Current rank
    int stars = 0;      // Monitors current stars

    for(int i = 0; i < N; i++){
        if(history[i] == 'W'){
            // Won ith match
            streak++;
            stars++;
            if(streak >= 3 && rank > 5)stars++;

            if(stars > level_stars(rank)){
                stars -= level_stars(rank);
                rank--;
            }
        }else{
            // Lost ith match
            streak = 0;
            
            if(rank < 21)stars--;
            if(rank == 20 && stars == -1)stars++;
            if(stars < 0 && rank != 20){
                rank++;
                stars = level_stars(rank)-1;
            }
        }
        if(rank == 0){
            cout << "Legend";
            return 0;
        }
    }

    cout << rank;

    return 0;
}
