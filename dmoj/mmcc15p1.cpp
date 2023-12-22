#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 5e5+5;
int pa[MM], sz[MM];
stack<pi> history; 
int root(int u) {
  if (pa[u]==u) return u;
  return root(pa[u]);
} 
void Init(int N) {
  for (int i=1;i<=N;i++) {
    pa[i] = i;
    sz[i] = 1;
  }
}
void AddEdge(int U, int V) {
  int ru = root(U);
  int rv = root(V);
  if (sz[ru]<sz[rv]) swap(ru, rv);
  history.push({ru, rv}); 
  // cout << "add: " << ru << " " << rv << endl;
  if (ru==rv) return;
  sz[ru] += sz[rv];
  pa[rv] = ru;
}
void RemoveLastEdge() {
  if (history.empty()) return;
  auto [u, v] = history.top();
  // cout << "remove: " << u << ' ' << v << '\n'; 
  history.pop();
  if (u != v) { 
    sz[u] -= sz[v];
    pa[v] = v;
  }
}
int GetSize(int U) {
  return sz[root(U)];
}
int main() {
  Init(5);
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  AddEdge(1, 2);
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  AddEdge(2, 4);
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  AddEdge(1, 4);
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  AddEdge(1, 5);
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  RemoveLastEdge();
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  RemoveLastEdge();
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  RemoveLastEdge();
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  RemoveLastEdge();
  for (int i=1;i<=5;i++) cout << pa[i] << ' '; cout << '\n';
  for (int i=1;i<=5;i++) cout << GetSize(i) << ' '; cout << '\n';
}