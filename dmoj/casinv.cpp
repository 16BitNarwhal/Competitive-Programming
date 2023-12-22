#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1;
typedef long long ll;
int n, ar[MM], dif[MM];
ll sum=0, pre[MM];
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> ar[i];
    sum += 1LL * ar[i] * n;
  }
  sort(ar, ar+n);
  
  for (int i=1;i<=n;i++) 
    pre[i] = ar[i-1] + pre[i-1];

  for (int i=0;i<n;i++) {
    int x;cin>>x;
    
    int pos = upper_bound(ar, ar+n, x) - ar + 1;
    if (pos <= n) {
      dif[pos]++;
      sum -= pre[n] - pre[pos-1];
      sum += 1LL * x * (n-pos+1);
    }

    if (ar[n-1] < x) {
      cout << "-1\n"; return 0;
    }
  }

  for (int i=1;i<=n;i++) {
    dif[i] += dif[i-1];
    if (dif[i]==n) {
      cout << "-1\n"; return 0;
    }
  }

  cout << sum << '\n';

}