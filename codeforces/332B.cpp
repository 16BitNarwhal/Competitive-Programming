#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, k, ar[MM];
ll sum[MM], mx[MM];
int main() {
  cin >> n >> k;
  for (int i=1;i<=n;i++) cin >> ar[i];
  for (int i=n;i>=1;i--) {
    sum[i] = sum[i+1] + ar[i];
    if (i+k<=n) sum[i] -= ar[i+k];
    mx[i] = max(sum[i], mx[i+1]);
  } 
  int a=0;
  for (int i=1;i<=n-k;i++) {
    if (sum[i] + mx[i+k] > sum[a] + mx[a+k]) 
      a = i;
  }
  int b=0;
  for (int i=a+k;i<=n;i++) {
    if (sum[i] == mx[a+k]) {
      b = i; break;
    }
  }
  cout << a << ' ' << b << '\n';
}