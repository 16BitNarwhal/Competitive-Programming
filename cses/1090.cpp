#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int a[MM];
int main() {
  int n,x;cin>>n>>x;
  for (int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  int cnt=0;
  for (int i=0,j=n-1;i<=j;) {
    if (a[i]+a[j]<=x) {
      cnt++; i++; j--;
    } else {
      cnt++; j--;
    }
  }
  cout << cnt << endl;
}
