#include <bits/stdc++.h>
using namespace std; 
int main() {
  string a, b;
  cin >> a >> b;
  int n=a.length(), m=b.length();
  if (m>n) { cout << "No\n"; return 0; }
  int cnt=0;
  for (int i=0;i<m;i++) {
    while (i+cnt < n && a[i+cnt] != b[i]) cnt++;
  }
  if (cnt>1) cout << "No\n";
  else cout << "Yes\n";
}