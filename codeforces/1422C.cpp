#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+2, mod = 1e9+7;
ll suf[N], ten[N];
int main() {
  int n;
  string s;
  cin >> s;
  n = s.length();
  ten[0] = 1;
  for (int i=1;i<N;i++) ten[i] = ten[i-1] * 10 % mod;
  suf[n] = 0;
  for (int i=n-1;i>=0;i--)
    suf[i] = (suf[i+1] + (ten[n-i-1] * (s[i]-'0') % mod)) % mod; 
  ll ans=0, sum=0, pre=0;
  for (int i=0;i<=n;i++) { 
    ll left = (sum * ten[n-i]) % mod;
    ll right = (suf[i] * (i+1)) % mod;
    ans = (ans + left + right - suf[0] + mod) % mod;
    
    pre = ((pre * 10)%mod + (s[i]-'0')%mod) % mod;
    sum = (sum + pre) % mod; 
  }
  cout << ans << '\n';
}

/*
i: sum of configs if remove segment [j, i] for any j<=i
123
---------
0 (take none away)
123
0*1000 + 123
---------
1 (take 1 away)
123, 23
1*100 + 23*2
---------
2 (take 2 or 12 away)
123, 13, 3
(1+12)*10 + 3*3
---------
3 (take 3 or 23 or 123 away)
123, 12, 1, 0
(1+12+123)*1 + 0*4
---------
*/