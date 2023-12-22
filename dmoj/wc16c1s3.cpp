#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, T;
pair<long long,int> a[MM]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M >> T;
  for (int i=0;i<N;i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a+N);  
  int ans=0;
  multiset<int> v;
  int cur=0;
  for (int m=0;m<N;m++) {
    int mxTake = (M-2*a[m].first)/T;
    if (mxTake<=0) continue;
    v.insert(a[m].second);
    cur += a[m].second;
    while (v.size() > mxTake) {
      cur -= *v.begin();
      v.erase(v.begin());
    } 
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}