#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define x first
#define y second
const int MM = 401;
string grid[MM];
vector<pi> pts;
void solve() {
    int n;cin>>n;
    pts.clear();
    for (int i=0;i<n;i++) {
        cin>>grid[i];
        for (int j=0;j<n;j++) {
            if (grid[i][j]=='*')
                pts.push_back({i,j});
        }
    }
    if (pts[0].x == pts[1].x) {
        int a = -1;
        if (pts[1].x==0) a=1;
        grid[pts[0].x+a][pts[0].y] = '*';
        grid[pts[1].x+a][pts[1].y] = '*';
    } else if (pts[0].y == pts[1].y) {
        int a = -1;
        if (pts[1].y==0) a=1;
        grid[pts[0].x][pts[0].y+a] = '*';
        grid[pts[1].x][pts[1].y+a] = '*';
    } else {
        grid[pts[0].x][pts[1].y] = '*';
        grid[pts[1].x][pts[0].y] = '*';
    }
    for (int i=0;i<n;i++)
        cout << grid[i] << '\n';
}
int main() {
    int t;cin>>t;
    while(t--) solve();
}