#include <bits/stdc++.h>
using namespace std;
int n; string s;
int count(int l, int r, char c) { 
  int cnt=0;
  for (int i=l;i<=r;i++) cnt += (s[i]==c);
  return cnt;
}
int calc(int l, int r, char c) {
  if (l==r) return s[l]!=c;
  int m = (l+r)/2;
  int lcnt = ((r-l+1)/2 - count(l, m, c)) + calc(m+1, r, c+1);
  int rcnt = ((r-l+1)/2 - count(m+1, r, c)) + calc(l, m, c+1);
  return min(lcnt, rcnt);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cin >> n >> s;
    cout << calc(0, n-1, 'a') << '\n';
  }
}