#include <bits/stdc++.h>
using namespace std;
const int SQRT = 31623;
const int MM = 6e6;
bool isPrime[MM], res[MM];
int n, m;
void sieve() {
  memset(isPrime, true, sizeof(isPrime));
  memset(res, true, sizeof(res));
  isPrime[0] = isPrime[1] = false;
  for (int i=2;i<SQRT;i++) {
    if (isPrime[i]) {
      for (int j=i*i;j<MM;j+=i) {
        isPrime[j]=false;
      }
      for (int j=(n/i)*i;j<=(m/i+1)*i;j+=i) {
        if (j-n<0) continue;
        if (j==i) continue;
        res[j-n]=false;
      }
    }
  } 
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  sieve();
  for (int i=n;i<=m;i++) {
    if (res[i-n] && i>1) {
      cout << i << '\n';
    }
  }
}