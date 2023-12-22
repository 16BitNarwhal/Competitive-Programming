#include <bits/stdc++.h>
using namespace std;
int ar[1010], n, p;
bool check(int i) {
  if (i>0 && ar[i]==ar[i-1]) return 1;
  if (i>1 && ar[i]==ar[i-2]) return 1;
  return 0;
}
int main() {
  cin >> n >> p;
  for (int i=0;i<n;i++) {
    char c;cin>>c;
    ar[i] = c-'a';
  }
  for (int i=n-1;i>=0;i--) {
    ar[i]++;
    while (ar[i]<p && check(i)) ar[i]++;
    if (ar[i]<p) {
      for (int j=i+1;j<=n;j++) {
        ar[j]=0;
        while (ar[j]<p && check(j)) ar[j]++;
      }
      break;
    }
    if (i==0) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i=0;i<n;i++) {
    cout << (char)(ar[i]+'a');
  }
}