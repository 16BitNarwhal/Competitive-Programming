#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5;
int N, K;
int cnt=0;
ll a[MM];
ll f(ll x) { int ret = x/12; return ret*12; }
ll rec(int i, ll x, int k) {
    if (cnt++>100) return 0;
    if (i>=N) return 0;  
    while (i<N-1 && a[i] <= x+12) i++; 
    cout << a[i] << ' ' << x << '\n';
    ll best = rec(i, f(a[i]), k) + f(a[i]-x); // wait
    if (k<K) best = min(best, rec(i, f(a[i]), k+1) + 12); // portal to next
    cout << i << ' ' << x << ' ' << k << ' ' << best << '\n';
    return best;
}
int main() {
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin>>a[i];
        a[i] = 1e9-a[i];
    }
    sort(a, a+N);
    for (int i=0;i<N;i++) cout<<a[i]<<' ';cout<<'\n';
    cout << rec(0, f(a[0]), 0);
}