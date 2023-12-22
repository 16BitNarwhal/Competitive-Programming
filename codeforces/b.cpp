#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int X, Y; 
vector<pair<string, string>> same, diff;
map<string, string> dsu;
vector<string> group[MM];
string root(string s) {
  if (dsu[s] == s) return s;
  return dsu[s] = root(dsu[s]);
}
void join(string a, string b) {
  a = root(a);
  b = root(b);
  if (a != b) dsu[b] = a;
}
bool equal(string a, string b) {
  return root(a) == root(b);
}
int main() {
  cin >> X;
  for (int i=0;i<X;i++) {
    string a, b;
    cin >> a >> b;
    same.push_back({a, b});
  }
  cin >> Y;
  for (int i=0;i<Y;i++) {
    string a, b;
    cin >> a >> b;
    diff.push_back({a, b});
  }
  int n;cin>>n;
  string s;
  getline(cin, s); // '\n' 
  for (int i=0;i<n;i++) {
    getline(cin, s);
    string cur="";
    for (char c : s) {
      if (c==' ') {
        group[i].push_back(cur);
        dsu[cur] = cur;
        cur = "";
      } else {
        cur += c;
      }
    }
    if (!cur.empty()) {
      group[i].push_back(cur); 
    } 
    for (string s : group[i]) {
      dsu[s] = s;
    }
  }
  for (int i=0;i<n;i++) {
    for (string s : group[i]) {
      join(s, group[i][0]);
    }
  }
  int ans=0;
  for (auto [a, b] : same) {
    if (!equal(a, b)) {
      ans++;
    }
  }
  for (auto [a, b] : diff) {
    if (equal(a, b)) {
      ans++;
    }
  }
  cout << ans << '\n';
}