#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    string win = "Bob";
    for (int i=1;i<n;i++) {
      if (a[i]<a[0]) {
        win = "Alice";
      }
    }
    cout << win << '\n';
  }
}