#include <bits/stdc++.h>
using namespace std;
// char str[10010];

bool isVowel(char c){
    char arr[] = "aeiouAEIOU";
    for(int i = 0; i < sizeof(arr)-1; i++){
        if(c == arr[i])return 1;
    }
    return 0;
}

bool comparator(string a, string b){
    return(a.size() < b.size());
}

bool comparator2(pair<string, int>& a, pair<string, int>& b){
    return a.second < b.second;
}

int main(){
    freopen("basic_string_in.txt", "r", stdin);
    // strcpy(str, "");

    while(1){
        char line[101]; fgets(line, 100, stdin);
        cout << line;
        string line2(line);

        string subs = "l";

        size_t location = line2.find(subs);
        // if(location != string::npos)cout << location << endl;
        
        int ctr = 1;
        while(1){
            location = line2.find(subs, location + ctr);
            if(location == string::npos)break;
            // else cout << location << endl;
            ctr++;
        }
    
        // Vowels, Consonants Counting
        int vow = 0, con = 0;
        string:: iterator it;
        for(it = line2.begin(); it != line2.end(); it++){
            if(isVowel(*it))vow++;
            else if(isalpha(*it)) con++;
        }

        cout << vow << " " << con << endl;
        if(strncmp(line, ".......", 7) == 0)break;


    }

    cout << endl << endl;

    vector<string> tokens;
    string strarr[1000];
    map<string, int> freq;

    string T = "for many lizards the lizards are for me but i am lizards";

    istringstream iss(T);
    string s;
    while(iss >> s)tokens.push_back(s);

    int strarr_ctr = 0;
    for(const string& s : tokens){
        strarr[strarr_ctr] = s;
        strarr_ctr++;
        freq[s]++;
        cout << s << endl;
    }

    sort(strarr, strarr+strarr_ctr, comparator);

    for(string s: strarr){
        cout << s << " ";
    }

    cout << endl;

    vector<pair<int, string>> sorter;
    for(auto const& [key,val] : freq){
        sorter.push_back(make_pair(val,key));
    }

    sort(sorter.begin(), sorter.end(),greater() );

    for(pair<int, string> x : sorter){
        cout << x.first << " " <<  x.second << endl;

    }

    return 0;
}