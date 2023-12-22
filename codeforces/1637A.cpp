#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+4;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> ar[i]; 
    }
    bool ans=true;
    for (int i=1;i<n;i++) {
      if (ar[i-1] > ar[i]) {
        ans = false;
      }
    }
    cout << (ans ? "NO" : "YES") << endl;
  }
}