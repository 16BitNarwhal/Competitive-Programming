#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b==0?a:gcd(b,a%b); }
int main() {
  int a, b;cin>>a>>b;
  int g = gcd(a, b);
  vector<int> div;
  for (int i=1;i*i<=g;i++) {
    if (g%i==0) {
      div.push_back(i);
      if (i != g/i) div.push_back(g/i);
    }
  } 
  sort(div.rbegin(), div.rend());
  int n;cin>>n;
  while (n--) {
    int lo, hi;
    cin>>lo>>hi;
    bool flag=0;
    for (int d : div) {
      if (lo <= d && d <= hi) {
        cout << d << '\n';
        flag=1;
        break;
      }
    }
    if (!flag) cout << "-1\n";
  }
}