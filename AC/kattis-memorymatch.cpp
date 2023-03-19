#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> pairs;
set<pairs> cardpos;
set<string> card;

void display(const set<pairs>& s)
{
    bool found = false;
  
    // range-based for loop
    for (auto const &x : s) {
        found = true;
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }
  
    if (not found) {
        cout << "No valid pair\n";
    }
    cout << endl;
}

int main(){
    int N, K, makepair = 0;

    cin >> N >> K;

    // Reading in cards
    int faceup = 0, unknown;
    int p1, p2; string c1, c2;
    for(int i = 0; i < K; i++){
        cin >> p1 >> p2 >> c1 >> c2;
        pairs x = make_pair(c1,p1);
        pairs y = make_pair(c2,p2);
        cardpos.insert(x);
        cardpos.insert(y);

        if(c1 == c2)faceup++;
    }
    unknown = N - cardpos.size();
    // display(cardpos);
    

    // Finding duplicates through difference of sets
    for (auto const &x : cardpos){
        card.insert(x.first);
    }
    int knownpairs = cardpos.size() - faceup - card.size();
    makepair += knownpairs;
    // cout << "known: " << knownpairs << endl;

    int knownsingles = card.size() - faceup - knownpairs;

    if(knownsingles == unknown)makepair += knownsingles;
    if((unknown == 2)&&(knownsingles==0))makepair++;

    cout << makepair;
    
    return 0; 
}
