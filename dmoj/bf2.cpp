#include <bits/stdc++.h>
using namespace std;

string s, ans;
int k;
int main() {
    cin >> s >> k;
    string cur = s.substr(0, k);
    ans = cur;
    for (int i=0;i+k<s.length();i++) {
        if(i!=0) { 
            cur.erase(0,1);
            cur.push_back(s[i+k]);
        }
        if(cur<ans) ans=cur;
    }
    cout<<ans<<'\n';
}