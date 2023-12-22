#include <bits/stdc++.h>
using namespace std;
vector<int> dig;
void sub(int i, int x) {
  if (dig[i]<x) {
    if (i==0) return;
    sub(i-1, 1);
    dig[i] += 10;
  }
  dig[i] -= x;
}
int main() {
  int t;cin>>t;
  while (t--) {
    dig.clear();
    string s;cin>>s;
    cout << s << '\n';
    for (char c : s)
      dig.push_back((int)(c-'0'));
    while (dig.size()>2) {
      int x = dig.back();
      dig.pop_back();
      sub(dig.size()-1, x);
      while (dig.size()>1 && dig[0]==0) {
        dig.erase(dig.begin());
      }
      for (int i:dig) cout << i;
      cout << '\n';
    }
    int x=0, p=1;
    while (!dig.empty()) {
      int d = dig.back();
      dig.pop_back();
      x += d * p;
      p *= 10;
    } 
    if (x%11==0) cout << "The number " + s + " is divisible by 11.\n";
    else cout << "The number " + s + " is not divisible by 11.\n";
    if (t>0) cout << '\n';
  }
}