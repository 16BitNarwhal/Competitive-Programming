#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+2;
int ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>ar[i];
    int g=1,s=1,b=1;
    while (g<n/2 && ar[g]==ar[g-1])
      g++;
    while (g+s<n/2 && (ar[g+s]==ar[g+s-1] || s<=g))
      s++;
    b = n/2 - g - s;
    for (int i=n/2-1;i>=0;i--) {
      if (ar[i]==ar[i+1]) b--;
      else break;
    }
    if (g>=s || g>=b) {
      cout << "0 0 0\n";
    } else {
      cout << g << ' ' << s << ' ' << b << '\n';
    }
  }
}