#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, L, C[31]; 
int main() {
  cin >> N >> L;
  for (int i=0;i<N;i++) cin>>C[i]; 
  for (int i=0;i<N-1;i++)
    C[i+1] = min(C[i+1], 2*C[i]);  
  ll ans=1e18;
  ll cur=0;
  for (int i=N-1;i>=0;i--) {
    int need = L / (1<<i);
    cur += (ll) need * C[i];
    L -= (need << i);
    ans = min(ans, cur + (L>0)*C[i]);
    // + C[i] is for buying all left bits with current 
    // ^^^ (L>0) is to check if there are any more left bits needed
  }
  cout << ans << '\n';
}