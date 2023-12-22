#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n;cin >> n;
  multiset<int> r;
  ll sum=0;
  for (int i=0;i<n;i++) {
    int x; cin>>x;
    if (x + sum >= 0) {
      r.insert(x);
      sum += x;
    } else if (!r.empty() && x >= (*r.begin())) {
      // if x + sum < 0 and x > min, remove min and add x
      sum -= (*r.begin());
      r.erase(r.begin());
      sum += x;
      r.insert(x);
    }
  }
  cout << r.size() << '\n';
}