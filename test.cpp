#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const ll MODS[2] = {1000000007, 1000000009}, BASE[2] = {131, 191};
ll mmul(ll a, ll b, ll mod) { return (a * b) % mod; }

ll append1(ll hsh, int val, int i) { return (hsh*BASE[i]+val)%MODS[i]; }
vector<ll> pows[2];
void init_pow(int N) {
    for (auto i = 0; i < 2; i++) {
        pows[i].resize(N + 1);
        pows[i][0] = 1LL;
        for (auto j = 1; j <= N; j++)
            pows[i][j] = mmul(pows[i][j - 1], BASE[i], MODS[i]);
    }
}
ll ghsh1(ll hr, ll hl, int sz, int i) {
    ll ret = (hr-pows[i][sz]*hl)%MODS[i];
    if (ret < 0) ret += MODS[i];
    return ret;
}
const int MN = 2e4 + 1;
int R, C;
string grid[MN];
ll* hsh[MN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_pow(MN);

    cin >> R >> C;
    for (auto i = 0; i < R; i++) cin >> grid[i];

    if (R > C) {
        string _tmp[MN];
        for (auto i = 0; i < C; i++) _tmp[i].assign(R, '$');
        for (auto i = 0; i < C; i++)
            for (auto j = 0; j < R; j++)
                _tmp[i][j] = grid[j][i];

        swap(R, C);
        swap(grid, _tmp);
    }
    for (auto i = 0; i < C; i++) {
        hsh[i] = new ll[R+1]; fill(hsh[i], hsh[i]+R+1, 0);
        for (auto j = 0; j < R; j++) {
            hsh[i][j+1] = append1(hsh[i][j], grid[j][i], 0);
        }
    }

    ll ans = 0;
    for (auto i = 0; i < R; i++) {
        for (auto j = i+1; j < R; j++) {
            for (auto k = C-1; k >= 0; ) {
                int nxt = k;
                while (nxt >= 0 && grid[i][nxt] == grid[j][nxt]) nxt--;
                if (nxt == k) {
                    k = nxt-1;
                    continue;
                }
                unordered_map<ll, int> fre;
                for (auto l = nxt+1; l <= k; l++) {
                    ll hs = ghsh1(hsh[l][j+1], hsh[l][i], j-i+1, 0);
                    fre[hs]++;
                }
                for (auto it : fre) ans += ll(it.second)*(it.second-1)/2;
                k = nxt;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
