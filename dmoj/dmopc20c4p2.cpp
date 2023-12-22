#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2;
map<ll, bool> row, col;
ll N, M, K, R[MM], C[MM];
int rptr=0, cptr=0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for (int i=0;i<K;i++) {
        ll r, c;
        cin >> r >> c;
        row[r] ^= 1; 
        col[c] ^= 1;
    }
    for (auto r:row)
        if (r.second) R[rptr++] = r.first;
    for (auto c:col)
        if (c.second) C[cptr++] = c.first; 
    cout << max(rptr, cptr) << '\n';
    for (int i=0;i<min(rptr, cptr);i++)
        cout << R[i] << ' ' << C[i] << '\n';
    for (int i=cptr;i<rptr;i++)
        cout << R[i] << ' ' << 1 << '\n';
    for (int i=rptr;i<cptr;i++)
        cout << 1 << ' ' << C[i] << '\n';
}