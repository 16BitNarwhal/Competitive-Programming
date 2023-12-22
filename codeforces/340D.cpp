// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 2e5+2;
// int n, bit[MM];
// int qry(int i) {
//   int mx = 0;
//   for (;i>0;i-=i&-i) mx = max(mx, bit[i]);
//   return mx;
// }
// void add(int i) {
//   int x = qry(i)+1;
//   for (;i<=n;i+=i&-i) bit[i] = max(bit[i], x);
// }
// int main() {
//   cin >> n;
//   for (int i=1;i<=n;i++) {
//     int x;cin>>x;
//     add(x);
//   }
//   cout << qry(n) << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, seg[3*MM];
int qry(int i, int tl, int tr, int l, int r) {
  if (l>r) return 0;
  if (l==tl && r==tr) return seg[i];
  int tm = (tl+tr)/2;
  return max(qry(i*2,tl,tm,l,min(r,tm)), 
             qry(i*2+1,tm+1,tr,max(l,tm+1),r));
}
void update(int i, int tl, int tr, int pos, int v) {
  if (tl==tr) {
    seg[i] = v;
    return;
  }
  int tm = (tl+tr)/2;
  if (pos <= tm) update(i*2,tl,tm,pos,v);
  else update(i*2+1,tm+1,tr,pos,v);
  seg[i] = max(seg[i*2], seg[i*2+1]);
}
int main() {
  cin >> n;
  int ans=0;
  for (int i=1;i<=n;i++) {
    int x;cin>>x;
    int mx = qry(1,1,n,1,x-1)+1;
    update(1,1,n,x,mx);
    ans = max(ans, mx);
  }
  cout << ans << '\n';
}