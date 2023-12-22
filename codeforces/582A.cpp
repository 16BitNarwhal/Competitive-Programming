#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int ans[505];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      int x;cin>>x;
      cnt[x]++;
    }
  }
  int pos = n-1;
  for (auto it=cnt.rbegin();it!=cnt.rend();it++) {
    int x = it->first;
    while (it->second--) {
      ans[pos] = x;
      for (int i=pos+1;i<n;i++)
        cnt[gcd(ans[pos], ans[i])] -= 2;
      pos--;
    }
  }
  for (int i=0;i<n;i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}