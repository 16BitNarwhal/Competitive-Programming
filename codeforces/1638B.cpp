#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, ar[MM], tmp[MM];
bool ans;
int main() {
  int t; cin>>t;
  while (t--) {
    cin >> n;
    ans = true;
    int odd=-1, even=0;
    for (int i=1;i<=n;i++) {
      cin >> ar[i];
      if (ar[i]%2==0) {
        if (ar[i] < even) ans = false;
        even = max(even, ar[i]); 
      } else {
        if (ar[i] < odd) ans = false;
        odd = max(odd, ar[i]); 
      }
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}
