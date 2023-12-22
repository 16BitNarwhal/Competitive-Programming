#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
  ll n, m, k;
  cin >> n >> m >> k;
  vector<int> vec(n+1), lst(n+1);
  k -= n;
  ll sum = 0;
  vec[1] = 1;
  lst[1] = 1;
  for (int i=2;i<=n;i++) {
    if (sum==k) vec[i]=vec[i-1];
    else {
      int x = vec[i-1] + 1;
      if (x>m) x = 1;
      int add = i-lst[x]-1;
      if (sum + add > k) {
        add = k - sum;
        sum += add;
        vec[i] = vec[i-add-1]; 
      } else {
        sum += add;
        vec[i] = x;
      } 
    }
    lst[vec[i]] = i;
  }
  if (sum != k) {
    cout << "-1\n";
    return 0;
  }
  for (int i=1;i<=n;i++) if (vec[i]==0) {
    cout << "-1\n";
    return 0;
  }
  for (int i=1;i<=n;i++) {
    cout << vec[i] << " ";
  }
  cout << '\n';
}