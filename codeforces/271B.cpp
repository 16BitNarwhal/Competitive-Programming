#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2e4;
int ar[501][501], nxtPrime[MM];
bool isPrime[MM];
void sieve() {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  for (int i=2;i<MM;i++) {
    if (isPrime[i]) {
      for (int j=2*i;j<MM;j+=i)
        isPrime[j] = false;
    }
  }
  for (int i=MM-2;i>=0;i--) {
    if (isPrime[i]) {
      nxtPrime[i] = i;
    } else {
      nxtPrime[i] = nxtPrime[i+1];
    }
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  sieve();
  int n, m;
  cin>>n>>m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> ar[i][j];
      ar[i][j] = nxtPrime[ar[i][j]] - ar[i][j]; 
    }
  }
  int mn=1e9;
  for (int i=0;i<n;i++) {
    int cnt=0;
    for (int j=0;j<m;j++) 
      cnt += ar[i][j];
    mn = min(mn, cnt);
  }
  for (int j=0;j<m;j++) {
    int cnt=0;
    for (int i=0;i<n;i++) 
      cnt += ar[i][j];
    mn = min(mn, cnt);
  }
  cout << mn << '\n';
}