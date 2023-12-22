#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+2;
int x,a,b,c;
bool isPrime[MM];
int cost(int n) {
  if (isPrime[n]) {
    return a + (x/n);
  } else if (n>1) {
    return b + (x/n);
  } else {
    return c + (x/n);
  }
}
int main() {
  memset(isPrime, 1, sizeof isPrime);
  isPrime[0] = isPrime[1] = 0;
  for (int i=2;i<MM;i++) {
    if (isPrime[i]) {
      for (int j=i*2;j<MM;j+=i)
        isPrime[j]=false;
    }
  }

  int t;cin>>t;
  while(t--) { 
    cin>>x>>a>>b>>c;
    int ans=1e9;
    for (int i=1;i*i<=x;i++) {
      if (x%i==0) {
        ans = min(ans, cost(i));
        if (i>1) ans = min(ans, cost(x/i));
      }
    }
    cout << ans << '\n';
  }
}