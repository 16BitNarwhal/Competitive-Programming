#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int pos[MM]; // position in vec
vector<int> vec[MM];
void join(int u, int v) {
  if (vec[pos[u]].size() < vec[pos[v]].size()) swap(u, v);
  int p = pos[v];
  for (int i : vec[p]) {
    vec[pos[u]].push_back(i);
    pos[i] = pos[u];
  }
  vec[p].clear();
}
int main() {
  int n;cin>>n; 
  for (int i=0;i<n;i++) {
    pos[i] = i;
    vec[i] = {i};
  }
  for (int i=0,u,v;i<n-1;i++) {
    cin>>u>>v; 
    join(u-1,v-1);
  }
  
  for (int j=0;j<n;j++) {
    if (!vec[j].empty()) {
      for (int i : vec[j]) cout << i+1 << ' ';
      cout << '\n';
      break;
    }
  }

}