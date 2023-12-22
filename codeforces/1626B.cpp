#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    string s;cin>>s;
    n = s.size();
    for (int i=0;i<n;i++) 
      ar[i] = s[i]-'0';
    bool flag=0;
    for (int i=n-1;i>0;i--) {
      if (ar[i] + ar[i-1] >= 10) {
        int x = ar[i] + ar[i-1];
        ar[i-1] = x/10;
        ar[i] = x%10;
        flag=1;
        break;
      }
    }
    if (flag) {
      for (int i=0;i<n;i++) cout << ar[i];
      cout << '\n';
      continue;
    } else {
      ar[1] += ar[0];
      for (int i=1;i<n;i++) cout << ar[i];
      cout << '\n';
    }
  }
  
}