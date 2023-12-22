#include <bits/stdc++.h>
using namespace std;
int n, ans=0;
int main() { 
  cin >> n;
  for (int i=2;i<=n;i++) {
    int x = i;
    set<int> s;
    for (int j=2;j*j<=x;j++) {
      while (x%j==0){ 
        s.insert(j);
        x/=j;
      }
    }
    if (x>1) s.insert(x);
    ans += (s.size()==2);
  }
  cout << ans << '\n';
}