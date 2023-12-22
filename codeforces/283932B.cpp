#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4+2;
const double EPS = 1e-6;
int n,k;
double ar[MM];
bool check(double x) {
  int sum=0;
  for (int i=0;i<n;i++)
    sum += (int)(ar[i]/x);
  return sum>=k;
}
int main() {
  cin>>n>>k;
  for (int i=0;i<n;i++) cin >> ar[i];
  double l=0,r=1e7;
  while (r-l > EPS) {
    double m = l + (r-l)/2;
    if (check(m)) l=m;
    else r=m;
  }
  cout << fixed;
  cout << l << '\n';
}