#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    string s;cin>>s;
    int n = s.size();
    int sum = 0;
    for (int i=0;i<n;i++) {
      sum += s[i] - 'a'+1;
    }
    if (n%2==0) {
      cout << "Alice " << sum << '\n';
    } else {
      int b = min(s[0]-'a'+1, s.back()-'a'+1);
      int a = sum - b;
      if (a>b) {
        cout << "Alice " << a-b << '\n';
      } else {
        cout << "Bob " << b-a << '\n';
      }
    }
  }
}