#include <bits/stdc++.h>
using namespace std;

int get_top(int b) {
	return __builtin_ctz(b);
}

int main() {

  while (true) {

  int n; cin>>n;
  if (n==0) break;

  vector<int> state(n+1);
  for (int i=1;i<=n;i++) {
    int x; cin>>x;
    state[i] = (1<<x);
  }

  map<vector<int>, int> dst;
  dst[state] = 0;
  
  queue<vector<int>> q;
  q.push(state);
  int ans=-1;

  while (!q.empty()) {
    state = q.front();
    q.pop();
    bool ok = true;
    for (int i=1;i<=n;i++) {
      if (__builtin_popcount(state[i])!=1 || get_top(state[i])!=i) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = dst[state]; 
      break;
    }
    for (int i=1;i<=n;i++) {
      if (state[i]==0) continue;
      int x = get_top(state[i]);
      if (i>1 && (state[i-1]==0 || x < get_top(state[i-1]))) {
        vector<int> new_state = state;
				int y = new_state[i];
				new_state[i] ^= (y&-y);
        new_state[i-1] |= (1<<x);
        if (dst.find(new_state) == dst.end()) {
          dst[new_state] = dst[state] + 1;
          q.push(new_state);
        }
      }
      if (i<n && (state[i+1]==0 || x < get_top(state[i+1]))) {
        vector<int> new_state = state;
				int y = new_state[i];
				new_state[i] ^= (y&-y);
        new_state[i+1] |= (1<<x);
        if (dst.find(new_state) == dst.end()) {
          dst[new_state] = dst[state] + 1;
          q.push(new_state);
        }
      }
    }
  }
  if (ans==-1) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';
  
  }
}