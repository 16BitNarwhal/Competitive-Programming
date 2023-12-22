#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM], n;
bool check(int i) {
  if (i==0 || i==n-1) return false;
  return (ar[i]>ar[i-1] && ar[i]>ar[i+1]);
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0;i<n;i++) 
      cin >> ar[i];
    int cnt=0;
    for (int i=1;i<n-1;i++) {
      if (ar[i] < ar[i-1] && ar[i] < ar[i+1] && check(i-1) && check(i+1)) {
        ar[i] = max(ar[i-1], ar[i+1]);
        cnt++;
      }
    }
    for (int i=1;i<n-1;i++) {
      if (check(i)) {
        ar[i+1] = ar[i];
        cnt++;
      }
    }
    cout << cnt << '\n';
    for (int i=0;i<n;i++) {
      cout << ar[i] << ' '; 
    }
    cout << '\n';
  }
}