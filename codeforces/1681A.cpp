#include <bits/stdc++.h>
using namespace std;


int main() {
  int t;cin>>t;
  while (t--) {
    int n1;
    cin >> n1;
    int mx1=0;
    for (int i=0;i<n1;i++) {
      int x;cin>>x;
      mx1 = max(mx1,x);
    }
    int n2;
    cin >> n2;
    int mx2=0;
    for (int i=0;i<n2;i++) {
      int x;cin>>x;
      mx2 = max(mx2,x);
    }
    if (mx1 > mx2) {
      cout << "Alice\nAlice\n";
    } else if (mx1 < mx2) {
      cout << "Bob\nBob\n";
    } else {
      cout << "Alice\nBob\n";
    }
  }
}