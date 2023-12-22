#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n, x;
  cin >> n >> x;
  ll s = 1LL * (n/2) * ((n/2)+1) / 2;
  int center = (n+1)/2;
  int m = n/2;
  if (s%2 != abs(center-x)%2) {
    if (n%2==0) center++;
    else m++;
  }
  cout << m << '\n';
  vector<int> a, b;
  int d = abs(center-x);
  for (int i=0;i<d;i++) {
    a.push_back(m);
    b.push_back(m-1);
    m-=2;
  }
  for (int i=0;i<m;i++) {
    if (m-i <= i) break;
    a.push_back(m-i);
    if (m%2==0) b.push_back(i+1);
    else b.push_back(i);
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  for (int i:a) cout << i << ' '; cout << '\n';
  for (int i:b) cout << i << ' '; cout << '\n';
  // for (int i=0;i<a.size();i++) {
  //   if (center < x) {
  //     cout << -a[i] << ' ';
  //     cout << b[i] << ' ';
  //   } else {
  //     cout << a[i] << ' ';
  //     cout << -b[i] << ' ';
  //   }
  // }
  // cout << '\n';
}