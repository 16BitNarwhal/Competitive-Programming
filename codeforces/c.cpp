#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (k<n || k>m*(m+1)/2 + m*(n-m)) {
    cout << "-1\n";
    return 0;
  }
  ll x, v;
  for (x=m;x>=1;x--) {
    v = x*(x+1)/2 + (x*(n-x));
    if (v < k) break;
  }
  x++; 
  v = x*(x+1)/2 + (x*(n-x));
  v -= k;
  m = x;
  vector<int> add(n);
  for (int i=0;i<n;i++) {
    if (i < n-m-v+1) {
      add[i] = m;
    } else if (i < n-m+1) {
      add[i] = m-1;
    } else {
      add[i] = n-i;
    }
  }
  vector<int> res(n);
  for (int i=0;i<m;i++) {
    res[i] = i+1;
  }
  for (int i=0;i<n;i++) {
    res[i+add[i]] = res[i];
  }
  for (int i : res) {
    cout << i << ' ';
  }
}