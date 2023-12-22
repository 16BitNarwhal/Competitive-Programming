#include <bits/stdc++.h>
using namespace std; 
const int MM = 2e5+2;
string a, b;
int ar[MM];
bool check(int n) {
  map<int, bool> del;
  for (int i=0;i<n;i++)
    del[ar[i]]=true;
  int j=0;
  for (int i=0;i<a.length();i++) { 
    if (!del[i]) { 
      if (j<b.length() && a[i]==b[j])
        j++; 
    }
  }
  return j==b.length();
}
int main() {
  cin>>a>>b;
  for (int i=0;i<a.length();i++) {
    cin >> ar[i]; ar[i]--;
  }
  int l=0,r=a.length()-1,ans=0;
  while (l<=r) {
    int m = l + (r-l)/2;
    if (check(m)) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  cout << ans << '\n';
}