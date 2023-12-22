#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
ll N, ar[MM];
map<ll,int> p;
void solve() {
    cin >> N;
    string s;cin>>s;
    for (int i=0;i<N;i++) ar[i] = (int)(s[i]-'0');
    p.clear(); p[0]=1;
    ll sum=0, ans=0;
    for (int i=0;i<N;i++) {
        sum += ar[i];
        int x = sum-i-1;
        ans += p[x];
        p[x]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}