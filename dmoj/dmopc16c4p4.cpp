#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, Q, ar[MM];
int main() {
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin >> ar[i];
  }
  cin>>Q;
  for (int i=0;i<Q;i++) {
    int l, r; cin >> l >> r;
    map<int,int> cnt;
    for (int j=l;j<=r;j++) 
      cnt[ar[j]]++;
    int res=0;
    for (auto it:cnt)
      res += (it.second % 2==0);
    cout << res << '\n';
  }
}
