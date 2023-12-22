#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {

    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    
    bool ans=true;
    for (int i=0;i<n;i++) {
      if (a[i]=='a' && b[i]=='c') 
        ans = false;
      if (a[i]=='c' && b[i]=='a') 
        ans = false;
    }
    if (!ans) {
      cout << "NO" << '\n';
      continue;
    }
    int start=0;
    while (a[start]=='b' && b[start]=='b') {
      start++;
    }
    queue<int> q;
    char first = a[start];
    if (a[start]=='b') first = b[start];
    char cur = first;
    int cnt=0;
    for (int i=start;i<n;i++) {
      if (a[i]==cur || b[i]==cur || (a[i]=='b' && b[i]=='b')) {
        cnt++;
      } else { 
        q.push(cnt);
        cnt=1;
        cur = a[i];
        if (a[i]=='b') cur = b[i];
      }
    }
    if (cnt) {
      q.push(cnt);
    }
    int i=start;
    while (!q.empty()) {
      int m = q.front(); 
      q.pop();
      int numA1=0, numA2=0, numC1=0, numC2=0;
      while (i<n && m--) { 
        if (a[i]=='a') numA1++;
        if (b[i]=='a') numA2++;
        if (a[i]=='c') numC1++;
        if (b[i]=='c') numC2++;

        if (numA1 < numA2 || numC1 > numC2) {
          ans=false;
          break;
        }

        i++;
      }
      if (numA1 != numA2 || numC1 != numC2) ans=false;
      if (!ans) break;
    }
    cout << (ans ? "YES" : "NO") << '\n';
  }
}