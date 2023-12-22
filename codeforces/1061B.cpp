#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
int a[MM];
int main() {
  int n, m;
  cin >> n >> m; 
  for (int i=0;i<n;i++) 
    cin >> a[i];
  sort(a, a+n);
  ll sum = 0;
  for (int i=0;i<n;i++) 
    sum += a[i];
  int h=0, keep=a[n-1];
  for (int i=0;i<n;i++) {
    if (a[i] > h) 
      h++;
    else
      keep++;
  }
  cout << sum - keep << '\n';
} 