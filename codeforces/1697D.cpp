#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, int> mp;
char qry(int x) {
  cout << "? 1 " <<x << endl;
  char res; cin >> res;
  return res;
}
int qry(int l, int r) {
  if (mp.count({l,r})) return mp[{l,r}];
  cout << "? 2 "<< l << " " << r << endl;
  int res; cin >> res;
  mp[{l,r}] = res;
  return res;
}
int last[26], n, numChar;
char ans[1001];
int main() {
  cin>>n;
  numChar = 1;
  char ch = qry(1);
  last[ch-'a'] = 1; // 1-indexed
  ans[1] = ch;
  for (int i=2;i<=n;i++) {
    int leftmost = i;
    for (int c=0;c<26;c++) {
      if (last[c]>0 && last[c]<leftmost) leftmost = last[c];
    }
    int q = qry(leftmost, i);
    if (q==numChar+1) {
      numChar++;
      ch = qry(i);
      last[ch-'a'] = i;
      ans[i] = ch;
      continue;
    }
    // bsearch
    vector<pair<int,char>> v;
    for (int c=0;c<26;c++) {
      if (last[c]) {
        v.push_back({last[c], (char)(c+'a')});
      }
    }
    sort(v.begin(), v.end()); 
    int l=0, r=v.size()-1;
    int pos = 0, num = v.size();
    while (l<=r) {
      int m = (l+r)/2; 
      q = qry(v[m].first, i);
      if (num - m == q) {
        pos = m;
        l = m+1;
      } else {
        r = m-1;
      }
    }
    ch = v[pos].second;
    last[ch-'a'] = i;
    ans[i] = ch;
  }
  cout << "! ";
  for (int i=1;i<=n;i++) cout << ans[i];
  cout << endl;
}