#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi; 
vector<pi> ar[10][10];
int val[10][10];
bool vis[10][10];
int find(int i, int j) {
  if (val[i][j] != -1) return val[i][j]; 
  if (vis[i][j]) return val[i][j];
  vis[i][j] = true;
  int sum=0;
  for (auto [a,b] : ar[i][j]) { 
    int x = find(a, b);
    if (x==-1) return val[i][j]=-1;
    sum += x;
  }
  return val[i][j]=sum;
}
int main() {
  memset(vis, false, sizeof vis);
  memset(val, -1, sizeof val);
  for (int i=0;i<10;i++) {
    for (int j=0;j<9;j++) { 
      string s;cin>>s;
      if (!(s[0]>='A' && s[0]<='J')) {
        val[i][j] = stoi(s);
        continue;
      }
      for (int k=0;k<(int)s.length();k+=3) {
        ar[i][j].push_back({s[k]-'A', s[k+1]-'1'});
      }
    }
  }
  for (int i=0;i<10;i++) {
    for (int j=0;j<9;j++) {
      int x = find(i, j);
      if (x==-1) cout << "* ";
      else cout << x << ' ';
    }
    cout << '\n';
  }
}