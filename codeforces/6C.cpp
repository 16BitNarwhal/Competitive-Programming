#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int ar[MM];
int main() {
  int n;
  cin>>n;
  for (int i=0;i<n;i++) 
    cin >> ar[i];
  int l=0,r=n-1;
  while (l<r) {
    int mn = min(ar[l], ar[r]);
    ar[l]-=mn;
    ar[r]-=mn;
    if (ar[l]==0) l++;
    if (l==r) ar[r]=0;
    if (ar[r]==0) r--;
  }
  if (ar[l]) l++;
  cout << l << ' ' << n-l << '\n';
}