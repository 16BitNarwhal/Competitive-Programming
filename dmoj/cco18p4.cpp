#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int R, C, K; unordered_map<ll, int> mp;
int Q(int r, int c) {
    ll k = r*(ll)(1e9)+c;
    if (mp.count(k)) return mp[k];
    cout << "? " << r << " " << c << '\n';
    int ret; cin >> ret;
    return mp[k] = ret;
}
int main() {
    cin >> R >> C >> K;
    int r1=1, r2=R, c1=1, c2=C;
    while (c1 < c2 || r1 < r2) {
        int cm = (c1+c2)/2, rm = (r1+r2)/2, mid = Q(rm,cm);
        if (c1<c2) {
            if (mid < Q(rm, cm+1)) c2 = cm;
            else c1 = cm+1;
        }
        if (r1<r2) {
            if (mid < Q(rm+1, cm)) r2 = rm;
            else r1 = rm+1;
        }
    }
    int ans = Q(r1,c1);
    cout << "! " << ans << '\n';
}