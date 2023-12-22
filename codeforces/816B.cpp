#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int ar[MM];
int main() {
  int n, k, q;
  cin>>n>>k>>q;
  for (int i=1;i<=n;i++) {
    int l,r;cin>>l>>r;
    ar[l]++;
    ar[r+1]--;
  }
  for (int i=1;i<MM;i++)
    ar[i] += ar[i-1];
  for (int i=1;i<MM;i++) {
    ar[i] = ar[i]>=k;
    ar[i] += ar[i-1];
  }
  while (q--) {
    int l,r;cin>>l>>r;
    cout<<ar[r]-ar[l-1]<<'\n';
  }
}