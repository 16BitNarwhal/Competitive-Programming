#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 100000, mod=1e9+7;
ll F[MM];
int main() {
  F[0] = F[1] = 1;
  for (int i=2;i<MM;i++) 
    F[i] = F[i-1] + F[i-2] % mod;
  int n, m; cin >> n >> m;
  cout << 2LL * (F[n] + F[m] - 1) % mod << '\n';
}