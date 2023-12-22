#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1;
int n, ar[MM];
int rec(int l, int r) {
  if (l>=r) return 0;
  if (ar[l]==ar[r]) return rec(l+1, r-1);
  else if (ar[l] < ar[r]) {
    ar[l+1] += ar[l];
    return rec(l+1, r) + 1;
  } else {
    ar[r-1] += ar[r];
    return rec(l, r-1) + 1;
  }
}
int main() {
  cin >> n;
  for (int i=0;i<n;i++) 
    cin >> ar[i];
  cout << rec(0, n-1) << '\n';
}