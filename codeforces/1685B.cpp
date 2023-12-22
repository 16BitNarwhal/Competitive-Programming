#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int A, B, AB, BA;
    cin >> A >> B >> AB >> BA;
    string s;cin>>s;
    int n=s.length(), cnt=0;
    for (char c:s) {
      if (c=='A') cnt++;
    }
    if (cnt != A+AB+BA || n-cnt != B+AB+BA) { 
      cout << "NO\n";
      continue;
    }

    vector<string> alternating;
    string cur="";
    for (int i=0;i<n-1;i++) {
      if (s[i]!=s[i+1]) {
        cur+=s[i];
      } else {
        if (cur.length()>0) {
          cur.push_back(s[i]);
          alternating.push_back(cur);
          cur="";
        }
      }
    }
    if (cur.length()>0) {
      cur.push_back(s.back());
      alternating.push_back(cur);
    }
    vector<int> v1, v2, v3;
    for (string s : alternating) {
      if (s.length()&1) v1.push_back(s.length()/2);
      else {
        if (s[0]=='A') v2.push_back(s.length()/2);
        else v3.push_back(s.length()/2);
      }
    }

    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());

    int extraAB=0, extraBA=0; 
    for (int& l : v2) {
      int mn = min(AB, l);
      AB -= mn; l -= mn;
      if (AB==0 && l>0) { 
        extraBA += l-1;
      }
    }
    for (int& l : v3) {
      int mn = min(BA, l);
      BA -= mn; l -= mn;
      if (BA==0 && l>0) {
        extraAB += l-1;
      }
    }

    AB -= extraAB;
    BA -= extraBA;
    
    for (int& l : v1) {
      int mn = min(AB, l);
      AB -= mn; l -= mn;
    }
    for (int& l : v1) {
      int mn = min(BA, l);
      BA -= mn; l -= mn;
    } 

    if (AB<=0 && BA<=0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }

  }
}
