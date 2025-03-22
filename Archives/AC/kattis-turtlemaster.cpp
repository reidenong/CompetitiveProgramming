// Kattis-turtlemaster
// not hard, tedious. just be careful of technicalities like how turtle may not end on D even thjough it goes apast it
// use of functions to call make things easier
#include <bits/stdc++.h>
using namespace std;
char grid[9][9];
bool bug = 0;
pair<int, int> Tpos, Dpos, newpos;
int x, y;   // Directional for move function

int dir = 1;
// direction is an int from 0-3
//...0
//3.....1
//...2
void R(){
    dir++;
    if(dir == 4)dir = 0;
}

void L(){
    dir--;
    if(dir == -1)dir = 3;
}

// given direction and location, return the block directly in front
pair <int,int> F(const pair <int,int>& loc){
    x = loc.first; y = loc.second;
    if(dir == 0)x--;
    else if(dir == 2)x++;
    else if(dir == 3)y--;
    else if(dir == 1)y++;
    return make_pair(x,y);
}

bool inGrid(int x){
    if(x >= 0 && x <= 8)return 1;
    return 0;
}

int main(){
    // Receiving grid, Input
    string commands;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'T')Tpos = make_pair(i,j);
            if(grid[i][j] == 'D')Dpos = make_pair(i,j);
        }
    }
    cin.ignore();
    getline(cin, commands);

    // Carry out each command
    int N;
    N = commands.length();
    for(int command = 0; command < N; command++){
        if(commands[command] == 'F'){           // Forwards in direction
            newpos = F(make_pair(Tpos.first, Tpos.second));
            if(inGrid(newpos.first) && inGrid(newpos.second)){
                if(grid[newpos.first][newpos.second] == '.' || grid[newpos.first][newpos.second] == 'D'){
                    grid[newpos.first][newpos.second] = 'T';
                    grid[Tpos.first][Tpos.second] = '.';
                    Tpos = newpos;
                }else{ // not grass, cannot walk
                    cout << "Bug!" << endl;
                    return 0;
                }
            }else{ // coord not in grid
                cout << "Bug!" << endl;
                return 0;
            }
        }else if(commands[command] == 'R')R();      // Turn Right
        else if(commands[command] == 'L')L();       // Turn left
        else{ // Fire Laser
            newpos = F(make_pair(Tpos.first, Tpos.second));
            if(inGrid(newpos.first) && inGrid(newpos.second)){
                if(grid[newpos.first][newpos.second] == 'I'){
                    grid[newpos.first][newpos.second] = '.';
                }else{ // not Ice, cannot lase
                    cout << "Bug!" << endl;
                    return 0;
                }
            }else{ // coord not in grid
                cout << "Bug!" << endl;
                return 0;
            }
        }
        /*
        // display for each command
        cout <<"command: " << commands[command] << endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cout << grid[i][j];
            }
            cout << endl ;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        */
    }
    

    // what about out of bounds for moving??? inGrid()
    // To double confimr that turtle ends on diamond, as further instructions may cause it to go other places
    if(Tpos == Dpos)cout << "Diamond!";
    else cout << "Bug!";
    

    return 0;
}
