// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int MM = 1e5+2;
// // from edge u to v with weight w
// struct edge { int u, v, w; bool isFlight; };
// int N, M, P, Q, row[MM], col[MM], cntR, cntC;
// vector<edge> vec;
// ll ans;

// bool cmp(edge a, edge b) { return a.w < b.w; }

// int root(int d, int p[]) {
//     if(d == p[d]) return p[d];
//     return p[d] = root(p[d], p);
// }

// int main() {
//     cin >> N >> M >> P >> Q;
//     for (int i=1,u,v,w; i<=P; i++) {
//         cin >> u >> v >> w; ans += (ll)w*N;
//         vec.push_back({u, v, w, 0});
//     }
//     for (int i=1,u,v,w; i<=Q; i++) {
//         cin >> u >> v >> w; ans += (ll)w*M;
//         vec.push_back({u, v, w, 1});
//     }
//     sort(vec.begin(), vec.end(), cmp);
//     for(int i=1; i<=N; i++) row[i] = i;
//     for(int i=1; i<=M; i++) col[i] = i;
//     cntR = N; cntC = M;
//     for(edge e: vec) {
//         if(e.isFlight) {
//             int ru = root(e.u, row), rv = root(e.v, row);
//             if (ru != rv) {
//                 row[ru] = rv; cntR--;
//                 ans -= (ll) e.w * cntC;
//             }
//         } else { 
//             int ru = root(e.u, col), rv = root(e.v, col);
//             if (ru != rv) {
//                 col[ru] = rv; cntC--;
//                 ans -= (ll) e.w * cntR;
//             }
//         }
//         if (cntR==1 && cntC==1) break;
//     }
//     cout << ans;
// }

#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
struct edge {
    int u, v, w;
    bool f;
    bool operator < (const edge &e) const {
        return w < e.w;
    }
};
vector<edge> vec;
// row: planet, col: city
int N, M, P, Q, drow[MM], dcol[MM];
int root(int d[], int u) {
    if (d[u] == u) return u;
    return d[u] = root(d, d[u]);
}
int main() {
    ll ans=0;
    cin >> N >> M >> P >> Q;
    for (int i=1;i<=P;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ans += 1LL*w*N;
        vec.push_back({u, v, w, true});
    }
    for (int i=1;i<=Q;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ans += 1LL*w*M;
        vec.push_back({u, v, w, false});
    }
    sort(vec.begin(), vec.end());
    for (int i=1;i<=N;i++) drow[i] = i;
    for (int i=1;i<=M;i++) dcol[i] = i;
    int cntR=N, cntC=M;
    for (auto [u,v,w,f] : vec) {
        if (f) {
            int ra = root(dcol, u);
            int rb = root(dcol, v);
            if (ra != rb) {
                dcol[ra] = rb;
                ans -= 1LL*w*cntR;
                cntC--;
            }
        } else {
            int ra = root(drow, u);
            int rb = root(drow, v);
            if (ra != rb) {
                drow[ra] = rb;
                ans -= 1LL*w*cntC;
                cntR--;
            }
        }
    }
    cout << ans << '\n';
}