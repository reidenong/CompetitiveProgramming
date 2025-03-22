// Kattis-tictactoe2
// both Xs n Os cannot win tgt
// tricky edge cases regarding win criterions and number of Xs and Os

#include <bits/stdc++.h>
using namespace std;
char grid[4][4];

int main(){
    int N;
    cin >> N;

    for(int tc = 0; tc < N; tc++ ){
        int Xnum = 0, Onum = 0;
        int Xwin = 0, Owin = 0;
        // Receiving TicTacToe grid, counting symbols
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'X')Xnum++;
                if(grid[i][j] == 'O')Onum++;
            }
        }
        // cout << "Numbers: " << Xnum << " " << Onum <<endl;

        // Check horizontals for win conditions
        for(int i = 0; i < 3; i++){
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
                if(grid[i][0] == 'X')Xwin++;
                else if(grid[i][0] == 'O') Owin++;
            }
        }
        // cout << "Ver: " << Xwin << " " << Owin << endl;

        // Check verticals for win conditions
        for(int i = 0; i < 3; i++){
            if(grid[0][i] == grid[1][i] && grid[2][i] == grid[0][i]){
                if(grid[0][i] == 'X')Xwin++;
                else if(grid[0][i] == 'O') Owin++;
            }
        }
        // cout << "Ver + Hor: " << Xwin << " " << Owin << endl;

        // Check diagonals for win conditions
        // Negative gradient
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            if(grid[1][1] == 'X')Xwin++;
            else if(grid[1][1] == 'O') Owin++;
        }
        if(grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]){
            if(grid[1][1] == 'X')Xwin++;
            else if(grid[1][1] == 'O') Owin++;
        }
        
        // cout << "Ver + Hor + Dia: " << Xwin << " " << Owin << endl;
        

        if(Onum > Xnum || abs(Onum - Xnum) > 1)cout << "no" << endl;
        else if(Xwin > 0 && Owin > 0)cout << "no" << endl;
        else if((Xwin > 0 && Owin == 0) && Xnum == Onum)cout << "no" << endl;
        else if((Xwin == 0 && Owin > 0) && Xnum > Onum)cout << "no" << endl;
        else cout << "yes" << endl;

        

    }

    return 0;
}
