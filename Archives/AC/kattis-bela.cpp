#include <bits/stdc++.h>
using namespace std;
string input;

int main(){
    int N;
    char B;
    cin >> N >> B;
    int points= 0;

    for(int i = 0; i < 4*N; i++){
        cin >> input;
        if( input[0] == 'A'){
            points += 11;
        }else if (input[0] == 'K'){
            points += 4;
        }else if(input[0] == 'Q'){
            points += 3;
        }else if (input[0] == 'J'){
            if(input[1] == B){
                points += 20;
            }else points += 2;
        }else if(input[0] == 'T'){
            points += 10;
        }else if(input[0] == '9'){
            if(input[1] == B){
                points += 14;
            }
        }
        
    }
    cout << points;
    return 0;
}