#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[(int)(1e5+2)];
bool solve(int n, int m, int k) {
  int odd=0; // num odds
  ll sum=0; // num pairs
  vector<int> v;
  for (int i=0;i<k;i++) {
    if (a[i]/n > 1) {
      odd += (a[i]/n % 2);
      sum += (a[i]/n/2);
    }
  }
  
  if (odd%2 == m%2) m-=odd; 
  else m-=max(0, odd-1);
  odd=0;

  if (m%2==1) {
    for (int i=0;i<k;i++) {
      if (a[i]/n >= 4) {
        sum--;
        odd++;
        break;
      }
    }
  }
  
  if (odd%2 == m%2) m-=odd; 
  else m-=max(0, odd-1);
  
  if (m%2==1) return false;
  return sum*2LL >= m;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0;i<k;i++) cin >> a[i];
    if (solve(n, m, k) || solve(m, n, k)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}