#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--){ 
    int n;cin>>n;
    if (n%3==0) {
      cout << n/3 << ' ' << n/3 << '\n';
    } else if (n%3==1) {
      cout << n/3+1 << ' ' << n/3 << '\n';
    } else {
      cout << n/3 << ' ' << n/3+1 << '\n';
    }
  }
}