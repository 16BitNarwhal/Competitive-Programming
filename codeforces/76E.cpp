#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n;
ll X[MM], Y[MM];
ll pX[MM], pX2[MM], pY[MM], pY2[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=1;i<=n;i++) 
    cin >> X[i] >> Y[i];
  for (int i=1;i<=n;i++) {
    pX[i] = pX[i-1] + X[i];
    pX2[i] = pX2[i-1] + X[i]*X[i];
    pY[i] = pY[i-1] + Y[i];
    pY2[i] = pY2[i-1] + Y[i]*Y[i];
  }
  ll ans=0;
  for (int i=1;i<=n;i++) {
    ans += pX2[i-1];
    ans -= 2*pX[i-1]*X[i];
    ans += (i-1)*X[i]*X[i];

    ans += pY2[i-1];
    ans -= 2*pY[i-1]*Y[i];
    ans += (i-1)*Y[i]*Y[i];
  }
  cout << ans << '\n';
  
}