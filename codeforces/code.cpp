#include <bits/stdc++.h>
using namespace std;

int main() {
  int _;
  cin >> _;
  while (_--) {
    map<char, char> mp;
    string from, to;
    cin >> from >> to;

    int ans = 0;
    for (int i = 0; i < from.size(); i++) {
      if (mp[from[i]] == 0) {
        mp[from[i]] = to[i];
      } else if (mp[from[i]] != to[i]) {
        ans = -1;
        break;
      }
    }

    if (ans == -1) {
      cout << "-1\n";
      continue;
    }

    // cycle check
    map<char, bool> in_cycle;
    for (auto [u, v] : mp) {
      if (u == v) continue;
      char cur = u;
      bool is_cycle = false;
      map<char, bool> vis;
      while (true) {
        vis[cur] = true;
        cur = mp[cur];
        if (cur == mp[cur]) break;
        if (cur == u) {
          is_cycle = true;
          break;
        }
        if (vis[cur]) break;
      }
      if (is_cycle) {
        cur = u;
        while (true) {
          in_cycle[cur] = true;
          cur = mp[cur];
          if (cur == u) break;
        }
      }
    }

    map<char, bool> finished;
    for (auto [u, v] : mp) {
      if (mp[u] == 0) continue;
      if (u == v) continue;
      if (finished[u]) continue;
      if (!in_cycle[u]) {
        ans++;
        finished[u] = true;
        continue;
      }
      set<char> cycle, cycle_targets;
      char cur = u;
      while (true) {
        cycle.insert(cur);
        cycle_targets.insert(mp[cur]);
        finished[cur] = true;
        cur = mp[cur];
        if (cur == u) break;
      }
      bool found = false;
      for (int i = 0; i < 26; i++) {
        if (found) break;
        for (char offset : {'A', 'a'}) {
          char c = offset + i;
          if (mp[c] != 0 && cycle.find(c) == cycle.end() && cycle_targets.find(mp[c]) != cycle_targets.end()) {
            found = true;
            break;
          }
        }
      }
      if (found) {
        ans += cycle.size();
        continue;
      }
      for (int i = 0; i < 26; i++) {
        if (found) break;
        for (char offset : {'A', 'a'}) {
          char c = offset + i;
          if (mp[c] == 0) {
            found = true;
            break;
          }
        }
      }
      if (found) {
        ans += cycle.size() + 1;
      } else {
        ans = -1;
      }
    }

    cout << ans << endl;
  }
}