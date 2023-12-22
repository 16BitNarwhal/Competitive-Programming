#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while (t--) {
    ll d,k;cin>>d>>k;
    ll x=0, y=0;
    while (1) {
      if (x <= y && (x+k)*(x+k) + y*y <= d*d) {
        x += k;
      } else if (y < x && (y+k)*(y+k) + x*x <= d*d) {
        y += k;
      } else {
        break;
      }
    }
    if (x==y) {
      cout << "Utkarsh\n";
    } else {
      cout << "Ashish\n";
    }
  }
}