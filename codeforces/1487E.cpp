#include <bits/stdc++.h>
using namespace std;
const int MM = 150005;
int n[4], cst[4][MM];
vector<int> cant[MM];
int main() { 
  for (int i=0;i<4;i++) cin >> n[i];
  for (int i=0;i<4;i++) for (int j=1;j<=n[i];j++) {
    cin >> cst[i][j];
  }
  
  multiset<int> s;
  for (int j=1;j<=n[0];j++) s.insert(cst[0][j]);
  
  for (int i=1;i<=3;i++) {
    memset(cant, 0, sizeof cant);
    int m; cin >> m;
    for (int j=0;j<m;j++) {
      int x,y; cin>>x>>y;
      cant[y].push_back(x);
    }
    for (int j=1;j<=n[i];j++) { 
      for (int x : cant[j]) {
        s.erase(s.find(cst[i-1][x]));
      }  
      int val = (s.size()==0) ? 1e9 : (*s.begin()); 
      cst[i][j] += val;
      for (int x : cant[j]) {
        s.insert(cst[i-1][x]);
      }
    } 
    s.clear();
    for (int j=1;j<=n[i];j++) s.insert(cst[i][j]); 
  }
  int ans = *s.begin();
  cout << (ans<1e9?ans:-1) << '\n';
}