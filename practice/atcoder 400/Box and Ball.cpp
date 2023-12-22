// https://atcoder.jp/contests/agc002/tasks/agc002_b
#include <bits/stdc++.h>
using namespace std;
const int MxN = 1e5+10;
int ar[MxN];
bool vis[MxN];

int main() {
    int n,m,c=0;
    cin>>n>>m;
    vis[0] = 1;
    for(int i=0;i<n;i++) ar[i]=1;
    for(int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        x--;y--;
        vis[y] |= vis[x];
        ar[x]--;
        ar[y]++;
        if (ar[x]==0) vis[x] = 0;
    }
    for(int i=0;i<n;i++)
        if(vis[i])
            c++;
    cout<<c<<"\n";
}