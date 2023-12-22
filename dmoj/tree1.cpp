#include <bits/stdc++.h>
using namespace std;
const int n = 4;
vector<int> a[n];
bool vis[n], flag = 1;

void dfs(int x, int p) {
    if(vis[x]) {
        flag = 0;
        return;
    }
    vis[x] = 1;
    for(int i:a[x]) {
        if(i!=p) dfs(i, x);
    }
}

int main() {
    for(int i=0;i<n;i++) vis[i]=0;
    for(int i=0;i<n;i++) for(int j=0,x;j<n;j++) {
        cin>>x;
        if(x) a[i].push_back(j);
    }
    dfs(0,0);
    for(int i=0;i<n;i++) 
        if(!vis[i]) flag=0; 
    cout<< (flag ? "Yes\n" : "No\n");
}