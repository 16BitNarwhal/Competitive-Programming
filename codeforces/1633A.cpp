#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> digit(int x) {
  vector<int> dig;
  while (x>0) {
    dig.push_back(x%10);
    x/=10;
  }
  return dig;
}
int cst(int x) {
  vector<int> b = digit(x);
  if (a.size() != b.size()) return 1e9;
  int c=0;
  for (int i=0;i<a.size();i++) {
    if (a[i]!=b[i]) c++;
  }
  return c;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    a = digit(n);
    int best=0, mn=1e9;
    for (int i=14;i<=999;i+=7) {
      int c = cst(i);
      if (c<mn) {
        mn=c;
        best=i;
      }
    }
    cout << best << '\n';
  }
}