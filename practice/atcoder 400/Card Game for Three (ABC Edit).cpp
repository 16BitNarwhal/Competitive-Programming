// https://atcoder.jp/contests/abc045/tasks/abc045_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string ar[3];
    cin>>ar[0]>>ar[1]>>ar[2];
    int t = 0;
    while(1) {
        if(ar[t].empty()) {
            cout<<(char) t+'A' <<"\n";
            return 0;
        }
        char c = ar[t][0];
        ar[t].erase(ar[t].begin());
        t = c-'a';
    }
}