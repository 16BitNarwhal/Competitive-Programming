#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
string s[MM];
int ar[26];
int root(int u) {
  if (ar[u]==u) return u;
  return ar[u] = root(ar[u]);
}
void join(int a, int b) {
  int rtA = root(a);
  int rtB = root(b);
  ar[rtB] = rtA;
}
int main() {
  for (int i=0;i<26;i++) ar[i]=i;
  int n;cin>>n;
  for (int i=0;i<n;i++){
    cin >> s[i];
    for (int j=1;j<s[i].length();j++) {
      int a = (int)(s[i][j-1]-'a');
      int b = (int)(s[i][j]-'a');
      join(a, b);
    }
  }
  set<int> rts;
  for (int i=0;i<n;i++) {
    int a = (int)(s[i][0]-'a');
    int rt = root(a);
    rts.insert(rt);
  }
  cout << rts.size() << '\n';
}