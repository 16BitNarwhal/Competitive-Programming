#include <bits/stdc++.h>
using namespace std; 
int main() { 
  string s;cin>>s;
  int n=s.length();
  vector<int> a;
  for (int i=0;i<n;i+=2) {
    char c = s[i];
    a.push_back(c-'0');
  }
  sort(a.begin(), a.end());
  cout << a[0];
  for (int i=1;i<a.size();i++) {
    cout << '+' << a[i];
  }
  cout << '\n';
}