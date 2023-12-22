#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n,m,k,l[100],r[100],p[MM],a[MM],ans[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>k;
  for (int i=1;i<=n;i++) p[i]=i;
  for (int i=0;i<m;i++) cin>>l[i]>>r[i]; 
  for (int i=0;i<m;i++) {
    for (int j=0;j<=(r[i]-l[i])/2;j++) 
      swap(p[l[i]+j], p[r[i]-j]); 
  }
  for (int i=1;i<=n;i++) {
    if (ans[i]!=0) continue;
    a[0] = i; 
    int j = p[i], c=1;
    while (j != i) {
      a[c] = j; 
      j = p[j];
      c++;
    }
    ans[i] = a[k%c];
    j = p[i];
    int c2=1;
    while (j != i) {
      ans[j] = a[(k+c2)%c];
      j = p[j];
      c2++;
    }
  }

  for (int i=1;i<=n;i++) {
    cout << ans[i] << '\n';
  }
}