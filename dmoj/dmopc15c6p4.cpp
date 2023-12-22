#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 2;
struct e { int u, v, w; };
int t, n, m, ds[MM], sz, cost;
vector<e> vec;
bool cmp(e a, e b) { return a.w < b.w; };

int root(int u) {
    if(ds[u]==u) return u;
    return ds[u] = root(ds[u]);
}

bool uni(int u, int v) {
    int ru = root(u), rv = root(v);
    if(ru!=rv) {
        ds[ru] = rv; sz--;
		return 1;
    }
	return 0;
}

int main() { 
	cin >> n >> m;
	sz = n; 
	for (int i=0, w; i<n-1; i++) {
		cin >> w;
		vec.push_back({i, i+1, w});
		ds[i] = i;
		if (i+m < n) vec.push_back({i, i+m, 0});
	}
	ds[n-1] = n-1;
	sort(vec.begin(), vec.end(), cmp);
	for (e ed : vec) { 
		if (uni(ed.u, ed.v))
			cost += ed.w;
		if (sz==1) break;
	}
	cout << cost; 
}