#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n, k;cin>>n>>k;
    vector<int> a(n);
    for (int &i : a) cin>>i;
    long long prod=1;
    for (int i : a) {
      prod*=i;
    }
    if (2023 % prod == 0) {
      cout<<"YES"<<endl;
      for (int i=1;i<k;i++) 
        cout<<1<<" ";
      cout << 2023 / prod << endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
}