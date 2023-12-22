#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;cin>>n;
    unordered_map<int,int> d,t;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        d[x]++;
    }
    cin>>m;
    for(int i=0;i<m;i++) {
        int x;cin>>x;
        t[x]++;
    }
    for(auto &i:t) {
        if(d[i.first] < i.second) {
            cout<<"NO\n";return 0;
        }
    }
    cout<<"YES\n"; return 0;
}