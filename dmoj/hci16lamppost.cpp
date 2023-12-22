#include <bits/stdc++.h>
using namespace std;

vector<int> a[1000000];

int main() {
    int n,c;cin>>n>>c;
    for(int i=0,u,v;i<c;i++) {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int idx=0,mx=0;
    for(int i=1;i<=n;i++) {
        if(a[i].size()>=mx) {
            idx = i;
            mx = a[i].size();
        }
    }
    cout<<idx<<'\n';
}