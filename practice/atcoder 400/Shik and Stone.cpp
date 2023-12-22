// https://atcoder.jp/contests/agc007/tasks/agc007_a
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<bool>> g, int i, int j, int n, int m) {
    g[i][j] = 0;
    if(i==n-1 && j==m-1) {
        for(int k=0;k<n;k++) {
            for(int l=0;l<m;l++) {
                if(g[k][l])
                    return 0;
            }
        }
        return 1;
    }
    bool d=0,r=0;
    if(i<n-1)
        d = dfs(g, i+1, j, n, m);
    if(j<m-1)
        r = dfs(g, i, j+1, n, m);
    return (d || r);
}

int main() {
    int n, m;cin>>n>>m;
    vector<vector<bool>> g(n, vector<bool>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch; cin>>ch;
            if(ch=='.') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    if (dfs(g, 0, 0, n, m)) {
        cout<<"Possible\n";
    } else {
        cout<<"Impossible\n";
    }

}