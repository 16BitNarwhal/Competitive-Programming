#include <bits/stdc++.h>
using namespace std;

int cost(string s) {
  int c=0;
  for (int i=0;i<s.length();i++) {
    for (int j=i+1;j<s.length();j++) {
      if (s[i]==s[j] && s[i+1]==s[j+1]) 
        c++;
    }
  }
  return c;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s="";
  int cnt=0;
  while (cnt<n) {
    for (int i=0;i<k;i++) {
      if (cnt>=n) break;
      s += ('a'+i);
      cnt++;
      for (int j=i+1;j<k;j++) {
        if (cnt>=n) break;
        s += ('a'+i);
        cnt++;
        if (cnt>=n) break;
        s += ('a'+j);
        cnt++;
      }
    }
  }
  cout << s << '\n';
}
