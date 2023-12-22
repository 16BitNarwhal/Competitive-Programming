#include <bits/stdc++.h>
using namespace std;
int qry(int a, int b, int c) {
  cout << "? " << a+1 << " " << b+1 << " " << c+1 << endl;
  int ret; cin >> ret; return ret;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<int> ar(n);
    for (int i=0;i<n;i++) {
      ar[i] = qry(i,(i+1)%n,(i+2)%n);
    }
    vector<int> res(n, -1);
    int a=-1,b=-1;
    for (int i=0;i<n;i++) {
      if (ar[i] != ar[(i+1)%n]) {
        res[i] = ar[i];
        res[(i+3)%n] = ar[(i+1)%n];
        
        a=i;
        b=(i+3)%n;
        if (ar[i]==1) swap(a,b);
      }
    }
    assert (a != -1);
    for (int i=0;i<n;i++) {
      if (res[i] == -1) {
        res[i] = qry(i, a, b);
      }
    }
    vector<int> ans;
    for (int i=0;i<n;i++) {
      if (res[i]==0) ans.push_back(i+1);
    }
    cout << "! " << ans.size() << ' ';
    for (int i:ans) cout<<i<< ' ';
    cout << endl;
  }
}