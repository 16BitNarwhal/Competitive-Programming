#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+2;
pair<int,int> a[MM];
int main() {
  int n,x;cin>>n>>x;
  for (int i=0;i<n;i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a,a+n);
  int i=0,j=n-1;
  while (i<j) {
    if (a[i].first + a[j].first > x) {
      j--;
    } else if (a[i].first + a[j].first < x) {
      i++;
    } else {
      cout << a[i].second+1 << " " << a[j].second+1 << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}