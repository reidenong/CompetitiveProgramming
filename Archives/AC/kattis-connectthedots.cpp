#include <bits/stdc++.h>
using namespace std;


int main(){
    while(1){
        // Receiving input
        char arr[101][101];
        pair<int, int> pos[70];
        int R = 0, C, Npos = 0;
        
        while(1){
            string line;
            getline(cin, line);
            if(line.empty() && R==0)return 0;
            if(line.empty())break;
            C = line.size();

            // Get positional indexes of all points
            for(int i = 0; i < C; i++){ 
                arr[R][i] = line[i];
                if(line[i] != '.'){
                    Npos++;
                    int key = (int)line[i];
                    if(key < 60){           // 0-9
                        pos[key-48] = make_pair(R, i);
                    }else if(key < 92){       // A-Z
                        pos[key-29] = make_pair(R, i);
                    }else{
                        pos[key-87] = make_pair(R, i);
                    }
                }
            }
            R++;
        }

        /*
        // Check Positional Array
        for(int i = 0; i < Npos; i++){
            cout << pos[i].first << " " << pos[i].second << endl;
        }
        */

        
        // Iterate through positional Array for N-1 times
        // >> fill in path from i to i+1
        for(int i = 0; i < Npos-1; i++){
            if(pos[i].first == pos[i+1].first){ 
                // Horizontal path
                for(int j = min(pos[i].second,pos[i+1].second)+1; j < max(pos[i].second,pos[i+1].second); j++){
                    if(arr[pos[i].first][j] == '|'){
                        arr[pos[i].first][j] = '+';
                    }else if(arr[pos[i].first][j] == '.'){
                        arr[pos[i].first][j] = '-';
                    }
                    
                }
            }else{
                // Vertical path
                for(int j = min(pos[i].first,pos[i+1].first)+1; j < max(pos[i].first,pos[i+1].first); j++){
                    if(arr[j][pos[i].second] == '-'){
                        arr[j][pos[i].second] = '+';
                    }else if(arr[j][pos[i].second] == '.'){
                        arr[j][pos[i].second] = '|';
                    }
                    
                }
            }
        }
        
        // Output Map
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
    }

    


    return 0;
}

