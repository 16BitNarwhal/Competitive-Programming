#include <bits/stdc++.h>
using namespace std;
int ar[(int)(4e5+5)];
int main() {
  int n,I;
  cin>>n>>I;
  for (int i=0;i<n;i++) cin>>ar[i];
  sort(ar,ar+n);
  if (I*8/n >= 23) {
    cout << "0\n";
    return 0;
  }
  int K = pow(2, I*8/n);
  int cur=1, ans=n-1;
  int l=0,r=0;
  while(r<n) {
    if (ar[r]!=ar[r+1]) cur++;
    r++;
    if (r==n) break;
    if (cur>K) {
      while (ar[l]==ar[l+1]) l++; 
      l++;
      cur--;
    }
    ans = min(ans, n-1-r + l); 
  }
  cout << ans << '\n';
}