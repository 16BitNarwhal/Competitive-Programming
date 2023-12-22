#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
int t, n, A[MM], B[MM], cntA[MM], cntB[MM];
int main() {
  cin>>t;
  while(t--){
    cin>>n;
    fill(cntA,cntA+n+1,0);
    fill(cntB,cntB+n+1,0);
    for (int i=0;i<n;i++) {
      cin>>A[i]>>B[i];
      cntA[A[i]]++;
      cntB[B[i]]++;
    }
    ll ans=1LL*n*(n-1)*(n-2)/6; 
    for (int i=0;i<n;i++) {
      ans -= 1LL * (cntA[A[i]]-1) * (cntB[B[i]]-1);
    }
    cout << ans << '\n';
  }
}