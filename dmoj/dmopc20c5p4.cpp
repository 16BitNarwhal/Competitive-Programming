#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base = 131;
int N, M;
vector<string> a, s;
unordered_map<ll,int> mp; 
ll ans=0;
int main() {
    cin >> N >> M;
    a.resize(N);
    for (int i=0;i<N;i++) cin>>a[i];
    if (N>M) {
        s.resize(M, string(N, ' '));
        for (int i=0;i<M;i++) 
            for (int j=0;j<N;j++) 
                s[i][j] += a[j][i];
        swap(s, a); swap(N, M);
    }
    for (int r1=0;r1<N;r1++) {
        vector<ll> hsh(M, 0);
        for (int r2=r1+1;r2<N;r2++) {
            for (int c=0;c<M;c++) hsh[c] = hsh[c]*base + a[r2][c];
            mp.clear();
            for (int c=0;c<M;c++) {
                if (a[r1][c] == a[r2][c]) {
                    ans += mp[hsh[c]]; 
                    mp[hsh[c]]++;
                } else {
                    mp.clear();
                }
            }
        }
    }
    cout << ans << '\n';
}