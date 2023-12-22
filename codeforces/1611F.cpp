#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    for (int i=0;i<n;i++)
      cin >> ar[i];
    ll cur=s;
    int ansL=-1, ansR=-1;
    int l=0;
    for (int r=0;r<n;r++) {
      cur += ar[r];
      while (l<n && cur < 0) {
        cur -= ar[l];
        l++;
      }
      if (r-l+1 >= ansR - ansL + 1) {
        ansL = l;
        ansR = r;
      }
    }
    if (ansL==-1)
      cout << "-1\n";
    else 
      cout << ansL+1 << " " << ansR+1 << endl;
  }
}