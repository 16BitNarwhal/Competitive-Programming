#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e7+1;
int d[MM], ans[MM];
ll s[MM]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fill(d, d+MM, -1);
  d[1] = 1;
  for (int i=2;i*i<MM;i++) {
    if (d[i]==-1) {
      d[i] = i;
      for (int j=i*i;j<MM;j+=i) {
        if (d[j]==-1) d[j] = i;
      }
    }
  }
  s[1] = 1;
  for (int i=2;i<MM;i++) {
    if (d[i]==-1) {
      d[i] = i; s[i] = i+1;
    } else {
      int j=i;
      s[i] = 1;
      while (j%d[i]==0) {
        j /= d[i];
        s[i] = s[i]*d[i] + 1; // eg. 1+2 --> (1+2)*2 + 1 --> 1+(2+4)
      }
      s[i] *= s[j]; // d(a*b) = d(a)*d(b) if gcd(a,b)=1
    }
  }
  fill(ans, ans+MM, -1);
  for (int i=MM-1;i>=0;i--) {
    if (s[i]<MM)
      ans[s[i]] = i;
  }
  int t;cin>>t;
  while(t--) {
    int c;cin>>c;
    cout << ans[c] << '\n';
  }
}