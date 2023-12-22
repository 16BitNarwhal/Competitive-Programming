#include<bits/stdc++.h>
using namespace std; 
typedef long double ld;
const int MM = 1e5+2;
int n, m;
vector<pair<int,int>> adj[MM]; 
vector<int> temp, ans; 
bool check(ld x) {
	vector<ld> dist(n+1, 1e9);
	vector<int> path(n+1, 1e9);
	path[1] = dist[1] = 0;
  for (int u=1;u<=n;u++) {
		for (auto &i : adj[u]) {
      int v = i.first;
      ld w = i.second;
			if (dist[v] > dist[u] + (w - x)) { 
				path[v] = u;
				dist[v] = dist[u] + (w - x); 
			}
		}
	} 
	if (dist[n] < 0) {
		temp = path;
		return true;
	} else return false;
} 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  cin >> n >> m;
	for (int i = 0; i < m; i++) {
    int u, v; ld w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
	} 
	ld l = -0.1, r = 100.1;
	for (int i=0;i<15;i++) {
		ld m = l + (r-l)/2; 
		if (check(m)) r=m;
		else l=m;
	} 
	for (int i=n; i>0; i=temp[i]) 
		ans.push_back(i);
	cout << ans.size()-1 << '\n';
  for (int i=ans.size()-1;i>=0;i--)
		cout << ans[i] << " ";
}