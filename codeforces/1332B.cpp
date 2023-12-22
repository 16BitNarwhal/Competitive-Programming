#include <bits/stdc++.h>
using namespace std;
int spf[1001], a[1001];
void sieve() {
  for (int i=2;i<=1000;i++) spf[i]=i;
  for(int i=2;i<=1000;i++) {
    if (spf[i]==i) {
      for(int j=2*i;j<=1000;j+=i) 
        if(spf[j]==j) spf[j]=i;
    }
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  sieve();
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    map<int,int> color;
    int c=1;
    for (int i=0;i<n;i++) {
      int v;cin>>v;
      a[i] = spf[v];
      if (color.find(a[i]) == color.end()) {
        color[a[i]] = c++;
      }
    }
    cout << color.size() << '\n';
    for (int i=0;i<n;i++) {
      for (auto it : color) {
        int p = it.first;
        if (a[i] % p == 0) {
          cout << it.second << ' ';
          break;
        }
      }
    }
    cout << '\n';
  }
  
}