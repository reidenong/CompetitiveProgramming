#include <bits/stdc++.h> 
using namespace std; 
char grid[101][101]; 
 
int main(){ 
    int N; 
    cin >> N;
    cin.ignore();
 
    for(int tc = 0; tc < N; tc++){ 
        int grid_len = 0, message_len; 
        string message;
        getline(cin, message);
        // cout << message << endl;
        message_len = message.length(); 
 
        // Derive grid length 
        while(pow(grid_len,2) < message_len)grid_len++; 
        
        // Input into grid 
        for(int i = 0; i < pow(grid_len, 2); i++){
            int row = floor(i/grid_len);
            if(i < message_len){
                grid[row][i%grid_len] = message[i];
            }else{
                grid[row][i%grid_len] = '*';
            }
        }

        /*
        for(int i = 0; i < grid_len; i++){
            for(int j = 0; j < grid_len; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        */

        for(int i = 0; i < pow(grid_len, 2); i++){
            int row = floor(i/grid_len);
            int col = (grid_len-1) - i%grid_len;
            if(grid[col][row] != '*'){
                cout << grid[col][row];
            }
        }
         
          
        // cout << grid_len << endl; 
        cout << endl;
    } 
 
}
