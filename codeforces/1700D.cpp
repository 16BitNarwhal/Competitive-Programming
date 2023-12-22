#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll N, Q, v[MM], tot[MM];
int main() {
  cin >> N;
  ll sum=0;
  for (int i=1;i<=N;i++) {
    cin >> v[i];
    sum += v[i];
  }
  for (int i=1;i<=N;i++) { // i=num pipes
    tot[i] = (sum+i-1)/i;
    cout << i << ' ' << tot[i] << '\n';
  }
  cin >> Q;
  while (Q--) {
    int x;cin>>x;
    
  }
}