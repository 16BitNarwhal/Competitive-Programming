#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t_;cin>>t_;
    for(int ds=1;ds<=t_;ds++) {
        int n; string s;
        cin>>n;
        getline(cin, s);
        cout<<ds<<" ";
        for(int i=1;i<(int)s.length();i++) {
            if(n==i) continue;
            cout<<s[i];
        } cout<<"\n";
    }
}