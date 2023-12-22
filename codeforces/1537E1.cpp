#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  string s;cin>>s;
  string pref="";
  string best;
  for (int i=0;i<min(n,k);i++) {
    pref += s[i];
    string cur="";
    for (int j=0;j<k;j++) 
      cur += pref[j%(i+1)];
      
    if (i==0) best = cur;
    else best = min(best, cur);
  }
  cout << best << '\n';
}