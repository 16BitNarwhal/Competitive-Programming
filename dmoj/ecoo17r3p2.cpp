#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, MOD=1e9+7;

struct node {
  int val, mx=0;
  node *pa; 
  map<int, node*> children_map;
  node(int v, node *p) : val(v), pa(p) {}
};

void put(node & root, vector<int> & path) { 
  node* next_node = nullptr;
  if (root.children_map.count(path[0])) {
    next_node = root.children_map[path[0]];
  } else {
    next_node = new node(path[0], &root);
    root.children_map[path[0]] = next_node;
    root.mx = max(root.mx, next_node->val);
  }
  
  if (path.size() > 1) {
    path.erase(path.begin());
    put(*next_node, path);
  }
}

ll ans;
void rec(node root) {
  for (auto & [k, v] : root.children_map) {
    rec(*v);
  } 
  ans = (ans + root.mx) % MOD;
}

int main() {
ios::sync_with_stdio(0); cin.tie(0);
int t=10;
while (t--) {
  int n;cin>>n;
  node root(0, nullptr);
  for (int i=0;i<n;i++) {
    vector<int> v;
    string s;cin>>s;
    int m=s.length();
    int cur=0;
    for (int j=0;j<m;j++) {
      if (s[j]=='.') {
        v.push_back(cur);
        cur = 0;
      } else {
        cur = (cur*10) + (s[j]-'0');
      }
    }
    v.push_back(cur);
    v.erase(v.begin());
    if (!v.empty()) 
      put(root, v);
  }
  ans=1;
  rec(root);
  cout << ans << '\n';
}
}