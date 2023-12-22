#include <bits/stdc++.h>
using namespace std;
int ar[101];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) 
    cin>>ar[i];
  sort(ar,ar+n);
  int x = (n-1)/2;
  for (int i=0;i<=x;i++) {
    if (ar[x - i] != 0) cout << ar[x - i] << " ";
    if (ar[x + i + 1] != 0) cout << ar[x + i + 1] << " ";
  }
  cout << '\n';
}