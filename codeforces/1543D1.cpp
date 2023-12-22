#include <bits/stdc++.h>
using namespace std;
bool q(int x) {
  cout << x << endl;
  bool ret;cin>>ret;return ret;
}
int main() {
  int t;cin>>t;
  while(t--) {
    int n,k; cin >> n >> k; 
    for (int i=0;i<n;i++) {
      int x=i;
      if (i) x ^= i-1;
      if (q(x))
        break;
    }
  }
}