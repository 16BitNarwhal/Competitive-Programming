#include <bits/stdc++.h>
using namespace std;
char ar[26];
int n, k;
int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) ar[i]='?';
  int cur=0;
  bool flag=1;
  while (k--) {
    int s; char l;
    cin >> s >> l;
    cur = (cur - s + (100*n)) % n; 
    if (ar[cur]==l || ar[cur]=='?') {
      ar[cur] = l;
    } else {
      flag = 0;
    }
  }
  if (!flag) {
    cout << "!\n";
    return 0;
  }
  
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (ar[i]==ar[j] && ar[i]!='?') { 
        cout << "!\n"; return 0;
      }
    }
  }

  for (int i=cur;i<n+cur;i++) cout << ar[i%n];
  cout << '\n';

}