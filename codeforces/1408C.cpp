// // using math
// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 1e5+2;
// int N, L;
// double a[MM];
// void solve() {
//   cin >> N >> L;
//   for (int i=0;i<N;i++) cin>>a[i];
//   int l=0, r=N-1;
//   double p1=0, p2=L, s1=1, s2=1;
//   double time=0;
//   while (l <= r) {
//     double t1 = (a[l] - p1) / s1;
//     double t2 = (p2 - a[r]) / s2;
//     if (t1 < t2) {
//       time += t1;
//       p1 = a[l];
//       l++;
//       s1++;
//       p2 -= s2 * t1;
//     } else if (t1 > t2) {
//       time += t2;
//       p2 = a[r];
//       r--;
//       s2++;
//       p1 += s1 * t2;
//     } else {
//       time += t1;
//       p1 = a[l]; p2 = a[r];
//       l++; r--;
//       s1++; s2++;
//     }
//   }
//   float x = (s2*p1 + s1*p2) / (s1 + s2);
//   time += (x - p1) / s1;
//   cout << fixed << time << '\n'; 
// }
// int main() {
//   ios::sync_with_stdio(0); cin.tie(0);
//   int t;cin>>t;
//   while(t--)solve();
// }

// using binary search
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, L;
double a[MM];
bool check(double t) {
  double p1=0, s1=1;
  int l=0;
  double temp=t; 
  while (p1<L) {  
    double t1;
    if (l>=N) t1 = (L - p1) / s1;
    else t1 = (a[l] - p1) / s1;
    if (t1 < temp) {
      if (l>=N) p1=L;
      else p1 = a[l];
      l++;
      s1++;
      temp -= t1;
    } else {
      p1 += s1 * temp;
      break;
    }
  }
  double p2=L, s2=1;
  int r=N-1;
  temp=t;
  while (p2>0) {
    double t2;
    if (r<0) t2 = (p2 - 0) / s2;
    else t2 = (p2 - a[r]) / s2;
    if (t2 < temp) {
      if (r<0) p2=0;
      else p2 = a[r];
      r--;
      s2++;
      temp -= t2;
    } else {
      p2 -= s2 * temp;
      break;
    }
  }
  return p1 < p2;
}
void solve() {
  cin >> N >> L;
  for (int i=0;i<N;i++) cin>>a[i];
  double l=0, r=L;
  while (l+(1e-6)<r) { 
    double m = (l+r)/2;
    if (check(m)) l=m+(1e-6);
    else r=m-(1e-6);
  }
  cout << fixed << l << '\n';
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) solve();
}