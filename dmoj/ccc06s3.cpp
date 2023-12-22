#include <bits/stdc++.h>
using namespace std;
struct P { int x, y; } ptA, ptB;
struct seg { P p, q; } ph;
int n, corners, res;
int ccw(P a, P b, P c) {
    int n = (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if (n>0) return 1;
    else if(n<0) return -1;
    else return 0;
}

bool intersect(seg a, seg b) {
    // bounding box
    if (max(a.p.x,a.q.x)<min(b.p.x,b.q.x) || 
        max(b.p.x,b.q.x)<min(a.p.x,a.q.x) || 
        max(a.p.y,a.q.y)<min(b.p.y,b.q.y) ||
        max(b.p.y,b.q.y)<min(a.p.y,a.q.y)) return 0;
    // rotation
    if (ccw(a.p, a.q, b.p)*ccw(a.p, a.q, b.q)>0 ||
        ccw(b.p, b.q, a.p)*ccw(b.p, b.q, a.q)>0) return 0;
    return 1;
}

int main() { 
    cin >> ph.p.x >> ph.p.y >> ph.q.x >> ph.q.y; 
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> corners;
        P fst, prev, nxt; cin >> fst.x >> fst.y;
        prev = fst; bool flg=0;
        for (int j=1;j<corners;j++) {
            cin >> nxt.x >> nxt.y;
            if (!flg && intersect(ph, {prev, nxt})) {
                flg=1; break;
            }
        }
        if (!flg && intersect(ph, {nxt, fst})) flg=1;
        res += flg;
    }
    cout << res;
}
/*
olympad solution vvv

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
#define x first
#define y second
pt R, J; int n, ans;
bool rectIntersect(pt p1, pt p2, pt q1, pt q2) {
    int xl = min(p1.x,p2.x), xr=max(p1.x,p2.x), 
        yb=min(p1.y,p2.y),yt=max(p1.y,p2.y);
    return min(q1.x, q2.x) <= xr && max(q1.x, q2.x) >= xl
        && min(q1.y, q2.y) <= yt && max(q1.y, q2.y) >= yb;
}
int cp(pt a, pt b, pt c) { // AB X AC
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
bool intersect(pt p1, pt p2, pt q1, pt q2) {
    return rectIntersect(p1, p2, q1, q2) && 
        1LL * cp(p1, p2, q1) * cp(p1, p2, q2) <= 0 && 
        1LL * cp(q1, q2, p1) * cp(q1, q2, p2) <= 0;
}

int main() {
    cin >> R.x >> R.y >> J.x >> J.y >> n;
    for (int i=1;i<=n;i++) {
        vector<pt> vec; int k=0; cin >> k;
        for (int j=1,x,y;j<=k;j++) {
            cin >> x >> y; vec.push_back({x,y});
        }
        bool flag = 0;
        for (int j=0;j<vec.size();j++) {
            if (intersect(R, J, vec[j], vec[(j+1)%k])) {
                flag = 1; break;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
}

*/