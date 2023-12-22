#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int MM = 1002;
// window data type and array
struct win { int x1, y1, x2, y2, v; } w[MM];
// n, t, diff array, #x's and #y's, real x and y values (from given index)
int n, t, dif[2*MM][2*MM], cntx, cnty, rx[2*MM], ry[2*MM];
// map for compressed x and y values (sorted) {value, index}
map<int,int> cx, cy;
long long ans=0;

int main() {
    cin >> n >> t;
    for (int i=1; i<=n; i++) {
        cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2 >> w[i].v;
        cx[w[i].x1] = cy[w[i].y1] = cx[w[i].x2] = cy[w[i].y2] = 0;
    }
    cntx = 0; for (auto &x : cx) { x.S = ++cntx; rx[x.S] = x.F; }
    cnty = 0; for (auto &y : cy) { y.S = ++cnty; ry[y.S] = y.F; }
    for (int i=1; i<=n; i++) {
        int xl = cx[w[i].x1], xr = cx[w[i].x2], yt = cy[w[i].y1], yb = cy[w[i].y2];
        dif[xl][yt] += w[i].v; dif[xr][yb] += w[i].v;
        dif[xr][yt] -= w[i].v; dif[xl][yb] -= w[i].v;
    }
    for (int i=1; i<cntx; i++) {
        for (int j=1; j<cnty; j++) { 
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            if (dif[i][j] >= t) ans += 1LL*(rx[i+1] - rx[i])*(ry[j+1] - ry[j]);
        }
    }
    cout<<ans;
}