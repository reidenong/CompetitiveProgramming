// Kattis-battleship
// Simulation based, main crux was realising they can give erraneous input after the game is won so
// advisable to put checks in place to realise when game is over and to ignore input
// stupid as hell they dont even state it clearly in the question

#include <bits/stdc++.h>
using namespace std;
char p1[31][31];
char p2[31][31];

int main(){
    int t, w, h, n;
    int x, y;
    cin >> t;
    
    // For each Test Case
    for(int tc = 0; tc < t; tc++){
        int p1_boat = 0, p2_boat = 0;
        int ignore = 0;
        bool last_turn = 0;
        bool playeronefiring = 1;
        cin >> w >> h >> n;

        // Receiving map input for p1, p2
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> p1[i][j];
                if(p1[i][j] == '#')p1_boat++;
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> p2[i][j];
                if(p2[i][j] == '#')p2_boat++;
            }
        }

        // simulation
        int p1_turns=0, p2_turns = 0;
        for(int k = 0; k < n; k++){
            cin >> x >> y;

            

            // Firing, check if boat is hit
            if(playeronefiring){ // p1 firing on p2
                if(p2[h-1-y][x] == '#'){ // Hit
                    p2[h-1-y][x] = '_';
                    p2_boat--;
                }else{playeronefiring = 0; p1_turns += 1;}
            }else{ // p2 firing on p1
                if(p1[h-1-y][x] == '#'){ // Hit
                    p1[h-1-y][x] = '_';
                    p1_boat--;
                }else if(last_turn){
                    ignore = n-k-1;
                    break;
                }else{playeronefiring = 1; p2_turns += 1;}
            }

            /*
            cout << "P1" << endl;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    cout << p1[i][j];
                }
                cout << endl;
            }
            cout << "~~~~~~~~~~~~~~~~~~" << endl;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    cout << p2[i][j];
                }
                cout << endl;
            }
            cout << endl;
            */
            
            // If player 2 gets turn to match player 1 even though all of two has no boats
            // if(playeronefiring && p2_boat == 0)playeronefiring = 0;
            if(last_turn && p1_boat == 0){
                ignore = n-k-1;
                break;
            }else if(last_turn && !playeronefiring) last_turn = 1;
            else if(playeronefiring && p2_boat == 0){
                last_turn = 1;
                playeronefiring = 0;
            }else if(p1_boat == 0 || p2_boat == 0){
                ignore = n-k-1;
                break;
            }
            
        }
        
        if(ignore > 0){
            // cout << "ignore: " << ignore << endl;
            for(int i = 0; i < ignore; i++){
                cin >> x >> y;
            }
        }

        // cout << p1_boat << " " << p2_boat << endl;
        if(p1_boat == 0 && p2_boat > 0)cout << "player two wins" << endl;
        else if(p1_boat > 0 && p2_boat == 0)cout << "player one wins" << endl;
        else cout << "draw" << endl;

    }


    return 0;
}
