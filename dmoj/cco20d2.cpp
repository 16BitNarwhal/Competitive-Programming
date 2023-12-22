// https://dmoj.ca/contest/cco20d2
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;cin>>n;
    vector<vector<int>> r(n+1), b(n+1);
    for(int i=2;i<=n;i++) {
        string s;cin>>s;
        for(int j=1;j<=s.length();j++) {
            if(s[j]=='R') {
                r[i].push_back(j);
                r[j].push_back(i);
            } else {
                b[i].push_back(j);
                b[j].push_back(i);
            }
        }
    }
    cout<<"R\n";
    for(int i=1;i<=n;i++) {
        cout<<i<<": ";
        for(int j=1;j<=n;j++) {
            cout<<r[i][j]<<" ";
        }
    }
    cout<<"\nB\n";
    for(int i=1;i<=n;i++) {
        cout<<i<<": ";
        for(int j=1;j<=n;j++) {
            cout<<b[i][j]<<" ";
        }
    }
}