#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;cin>>s;
    map<char, bool> mp;
    for (char c:s)
        mp[c] = 1;
    int cnt=0;
    string s2 = "BFTLC";
    for (char c:s2) { 
        if (!mp[c]) {
            cout << c << '\n';
            cnt++;
        }
    }
    if (cnt==0) cout<<"NO MISSING PARTS\n";
}