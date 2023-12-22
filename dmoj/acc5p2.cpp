// https://dmoj.ca/problem/acc5p2
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    string s;cin>>s;
    vector<string> ar = {
        "DMOJ", 
        "DMO", "DMJ", "DOJ", "MOJ", 
        "DM", "DO", "DJ", "MO", "MJ", "OJ"
    };
    for(string i : ar) {
        if(s.find(i) != string::npos) {
            cout<< 4-(i.length()) << "\n";
            return 0;
        }
    }
    cout << 3 << "\n";
}