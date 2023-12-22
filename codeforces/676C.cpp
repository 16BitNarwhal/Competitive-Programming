#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,k, ar[MM], ans=0;
void calc() {
  int l=0,r=0,cnt=0;
  while (r<n) {
    cnt += ar[r];
    if (cnt>k) {
      while (!ar[l]) l++;
      l++;
      cnt--;
    }
    r++;
    ans = max(ans, r-l); 
  }
}
int main() {
  cin>>n>>k;
  for (int i=0;i<n;i++) {
    char c;cin>>c;
    ar[i] = (c-'a');
  }
  calc();
  for (int i=0;i<n;i++) ar[i] = !ar[i];
  calc();
  cout << ans << '\n';
}