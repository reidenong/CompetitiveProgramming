#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, string, string>> agename;

bool sort_sec_descending(const tuple<int, string, string>& a, const tuple<int, string, string>& b){
    return (get<1>(a) > get<1>(b));
}

void print_vt(vector<tuple<int, string, string>> const & data){
    for(auto row : data){
        cout << get<0>(row) << get<1>(row) << get<2>(row) << endl;
    }
}

int main(){
    int N;
    cin >> N;

    int age; 
    string last_name, first_name;
    for(int i = 0; i < N; i++){
        cin >> age >> last_name >> first_name;
        agename.emplace_back(age, last_name, first_name);
    }

    sort(agename.begin(), agename.end());
    sort(agename.begin(), agename.end(), sort_sec_descending);

    print_vt(agename);

}
