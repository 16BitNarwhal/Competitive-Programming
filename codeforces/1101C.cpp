#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct seg {
  int l, r; 
};
bool cmp(pair<seg,int> a, pair<seg,int> b) {
  return a.first.r < b.first.r;
}
pair<seg, int> ar[MM];
int t, n, group[MM], L[MM], R[MM];
bool intersect(seg a, seg b) {
  return (a.r >= b.l && b.r >= a.l);
}
seg join(seg a, seg b) {
  seg ret;
  ret.l = min(a.l, b.l);
  ret.r = max(a.r, b.r);
  return ret;  
} 
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> ar[i].first.l >> ar[i].first.r;
      ar[i].second = i+1;
    }
    sort(ar, ar+n, cmp);
    R[0]=0;
    for (int i=0;i<n-1;i++) {
      R[i] = max(R[i], ar[i].first.r);
      R[i+1]=R[i];
    }
    L[n-1]=1e9;
    for (int i=n-1;i>0;i--) {
      L[i] = min(L[i], ar[i].first.l);
      L[i-1]=L[i];
    }
    int cut=-1;
    for (int i=0;i<n-1;i++) {
      if (R[i]<L[i+1]) {
        cut=i; break;
      }
    }
    if (cut==-1) {
      cout << "-1\n"; continue;
    }
    fill(group, group+n+1, 0);
    for (int i=0;i<=cut;i++) {
      group[ar[i].second]=1;
    }
    for (int i=cut+1;i<n;i++) {
      group[ar[i].second]=2;
    }
    for (int i=1;i<=n;i++) {
      cout << group[i] << ' ';
    }
    cout << '\n';
  }
}