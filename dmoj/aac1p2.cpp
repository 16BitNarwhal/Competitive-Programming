#include <bits/stdc++.h>
using namespace std;
const int MM =  1e6+2;
typedef long long ll;
ll N, D, K, X, P, ar[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D >> K >> X;
    for (int i=0;i<N;i++) cin >> ar[i];
    sort(ar, ar+N, greater<ll>());
    cin >> P;
    int i=0;
    while (K>0 && i<N) {
        if (ar[i] < P) break;
        while (K>0 && ar[i] >= P) {
            ar[i] = ar[i] * (100-X) / 100;
            K--;
        }
        i++;
    }
    if (i==N || ar[i] < P) cout << "YES\n";
    else cout << "NO\n";
}