#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int MAXN = 20000001;
pair<int,int> jim[11];          // Array to track jim time
bool ppl[10][MAXN];    // Array to simulate time
int delay[10] = {0};            // Array to track delays
int delay_MOD[10];

int main(){
    int x, y;
    // Receive Jim schedule input
    for(int i = 0; i < 10; i++){
        cin >> x >> y;
        jim[i] = make_pair(x, y);
    }

    int u,r,t;
    // Received other peoples input (u,r,t)
    for(int i = 0; i < 10; i++){
        cin >> u >> r >> t;

        delay_MOD[i] = u+r;
        
        // Simulate for each machine
        for(int j = t; j < MAXN; j++){
            if( (j - t )%(u + r) < u )ppl[i][j] = 1;
        }
        
        /*
        for(int j = 0; j < 16; j++){
           cout << ppl[i][j];
        }
        cout << endl;
        */
    }

    // Simulate for all time now
    int curr_time = 0, curr_machine = 0, rounds = 0, time_left_mac = jim[0].first, time_left_rec = jim[0].second;
    bool waiting = 1, gymming = 0, resting = 0, container=1;
    while(1){
        
        // Gymming
        if(ppl[curr_machine][curr_time - delay[curr_machine]] == 0 && waiting){
            gymming = 1;
            waiting = 0;
        }
        if(gymming){
            time_left_mac--;
            if(ppl[curr_machine][curr_time - delay[curr_machine]]){
                delay[curr_machine]++;
                delay[curr_machine] %= delay_MOD[curr_machine];

                /*
                ppl[curr_machine][MAXN-1] = ppl[curr_machine][curr_time];
                for(int j = curr_time+1; j < MAXN-1; j++){
                    container = ppl[curr_machine][j];
                    ppl[curr_machine][j] = ppl[curr_machine][MAXN-1];
                    ppl[curr_machine][MAXN-1] = container;
                }
                */
            }
        }

        // Resting
        if(resting)time_left_rec--;
        if(time_left_rec == 0){
            waiting = 1;
            resting = 0;
            curr_machine++;
            if(curr_machine == 10){
                curr_machine = 0;
                rounds++;
                // cout << rounds <<"round done" << curr_time << endl;
            }
            time_left_mac = jim[curr_machine].first, time_left_rec = jim[curr_machine].second;
        }
        if(time_left_mac == 0){
            resting = 1;
            gymming = 0;
        }

        // Status Update
        // cout << rounds << " " << curr_machine<< " WGR-" << waiting << gymming << resting << " " << time_left_mac <<" " << time_left_rec << endl;


        curr_time++;


        if(rounds == 3)break;
        
        //if(curr_time >= 50)break;
    }

    cout << curr_time - jim[9].second;   // dont include recovery time

    return 0;
}
