#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int a[MM], b[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    int off=0;
    multiset<int> s;
    bool ans = true;
    for (int i=n-1;i>=0;i--) {
      if (b[i]==a[i+off]) continue;
      if (i<n-1 && b[i]==b[i+1]) {
        off++;
        s.insert(b[i]);
      } else {
        if (s.find(a[i+off])!=s.end()) {
          s.erase(s.find(a[i+off]));
          off--;
          i++;
        } else {
          ans = false;
          break;
        }
      }
    }
    
    cout << (ans ? "YES" : "NO") << '\n';
  }
}