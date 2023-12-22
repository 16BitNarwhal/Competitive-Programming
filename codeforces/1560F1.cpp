#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> vec;
bool fun(int x, int i) {
  vector<int> v(vec);
  v[i] = x; 
  set<int> unique;
  for (int j=0;j<=i;j++) {
    unique.insert(v[j]);
  }
  int y;
  if (unique.size() == k || i==0) y = *unique.begin();
  else if (unique.size() < k) y = 0;
  if (unique.size() <= k) {
    // if ans, output
    for (int j=0;j<=i;j++) cout << v[j];
    for (int j=i+1;j<n;j++) cout << y;
    cout << '\n';
    return true;
  }
  return false;
}
int main() {
  int t;cin>>t;
  while (t--) {
    string s; 
    cin >> s >> k; 
    vec.clear();
    set<int> unique;
    for (char c : s) { 
      vec.push_back((int)(c-'0'));
      unique.insert(vec.back());
    }
    if (unique.size() <= k) {
      cout << s << '\n';
      continue;
    }
    n=vec.size();
    bool ans=false;
    for (int i=n-1;i>=0;i--) {
      for (int x=vec[i]+1;x<=9;x++) {
        if (fun(x, i)) {
          ans=true;
          break;
        }
      }
      if(ans)break;
    }
  }
}