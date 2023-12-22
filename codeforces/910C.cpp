#include <bits/stdc++.h>
using namespace std;
pair<int, bool> ar[26];
bool cmp(pair<int,bool> a, pair<int,bool> b) {
  return a.first > b.first;
}
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    string s;cin>>s;
    int m=s.size(), p=1;
    ar[(int)(s[0]-'a')].second =true;
    for (int j=m-1;j>=0;j--) {
      ar[(int)(s[j]-'a')].first += p;
      p *= 10;
    }
  }
  sort(ar, ar+26, cmp); 
  bool usedZero=false;
  int ans=0, dig=1; 
  for (int i=0;i<26;i++) {
    if (!usedZero && !ar[i].second) {
      usedZero = true;
    } else {
      ans += ar[i].first * dig;
      dig++;
    }
  }
  cout << ans << '\n';
}