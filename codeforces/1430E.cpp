#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM], bit[MM];
void add(int i) {
  for (;i<=n;i+=i&-i) bit[i]++;
}
int get(int i) {
  int ret=0;
  for (;i>0;i-=i&-i) ret+=bit[i];
  return ret;
}
int main() {
  cin>>n;
  string s;cin>>s;
  string rev = s;
  reverse(rev.begin(),rev.end());
  for (char c='a';c<='z';c++) {
    int j=0;
    for (int i=0;i<n;i++) {
      if (s[i] != c) continue;
      while (rev[j] != c) j++;
      ar[i] = j+1;
      j++;
    }
  }
  long long ans=0;
  for (int i=n-1;i>=0;i--) {
    ans += get(ar[i]);
    add(ar[i]);
  }
  cout << ans;
}