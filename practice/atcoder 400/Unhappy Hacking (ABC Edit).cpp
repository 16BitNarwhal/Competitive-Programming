// https://atcoder.jp/contests/abc043/tasks/abc043_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    string s;cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='B') {
            if(i>0) {
                s.erase(i-1, 2);
                i-=2;
            } else {
                s.erase(i, 1);
                i--;
            }
        }
    }
    cout<<s<<"\n";
}