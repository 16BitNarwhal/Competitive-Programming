#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    vector<int> v;
    for (int i=0;i<n;i++) {
      if (s[i]=='0') continue;
      for (int j=n-1;j>i;j--) {
        if (s[j]=='1') continue;
        v.push_back(i);
        v.push_back(j);
        swap(s[i], s[j]);
        break;
      }
    }
    sort(v.begin(), v.end());
    if (v.size()==0) {
      cout<<"0\n";
    } else {
      cout << "1\n";
      cout << v.size() << '\n';
      for (int i=0;i<v.size();i++) {
        cout<<v[i]+1<<' ';
      }
      cout << '\n';
    }
  }
}