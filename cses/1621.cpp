#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+2;
int a[MM];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) 
    cin >> a[i];
  sort(a, a+n);
  int cnt=1;
  for (int i=1;i<n;i++) {
    if (a[i] != a[i-1]) cnt++;
  }
  cout << cnt << endl;
}