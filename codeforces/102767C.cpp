#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM];
map<int,int> cnt;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> ar[i];
    }
    int mx = 0, cnt = 0;
    for (int i=0;i<n-1;i++)
      mx = max(mx, gcd(ar[i], ar[i+1]));
    for (int i=0;i<n;i++) {
      int c=0;
      for (int j=i;j<n;j++) {
        if (ar[j]%mx==0) c++;
        else break;
      }
      cnt = max(cnt, c);
      i += c;
    }
    cout << mx << ' ' << cnt << '\n';
  }
}
