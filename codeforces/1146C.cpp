#include <bits/stdc++.h>
using namespace std;
int q(set<int> a, set<int> b) { 
  cout << a.size() << ' ' << b.size() << ' ';
  for (int i:a)cout<<i<<' ';
  for (int i:b)cout<<i<<' ';
  cout << '\n';
  int ret;cin>>ret;return ret;
}
int main() {
  int t;cin>>t;
  while(t--) {
    int n;cin>>n;
    set<int> a={1};
    set<int> b;
    for (int i=2;i<=n;i++) b.insert(i);
    int x=q(a,b);
    int l=2,r=n;
    int res=1;
    while (l<r) {
      int m = (l+r)/2;
      
      b.clear();
      for (int i=l;i<=m;i++) b.insert(i);
      int x1=q(a,b);

      if (x1 == x)
        r = m, res=r;
      else 
        l = m+1, res=l;
      
    }
    a = {res};
    b.clear();
    for (int i=1;i<=n;i++) if (i!=res) b.insert(i);
    x = q(a,b);
    cout << "-1 " << x << '\n';
  }
  
}