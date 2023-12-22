#include <bits/stdc++.h>
using namespace std;

int main() {
  int v1, v2;
  cin >> v1 >> v2;
  int t, d;
  cin >> t >> d;
  int ans=0;
  int mx=11;

  if (d==0) {
    cout << v1*t << '\n'; // v1==v2
    return 0;
  }

  for (int mx=max(v1,v2);mx<1000;mx++) {
    int t1 = (mx-v1-1)/d+1;
    int t2 = (mx-v2-1)/d+1;
    int sum1 = t1*(2*v1 + (t1-1)*d)/2;
    int sum2 = t2*(2*v2 + (t2-1)*d)/2;
    int t3 = t-t1-t2;
    if (t3>=0) {    
      int sum3 = t3*mx;
      ans = max(ans, sum1+sum2+sum3);
    }
  }
  cout << ans << '\n';
}