#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2;
typedef long long ll;
int n, k;
pair<ll,ll> ar[MM];
ll cum[MM];
int main() {
  cin >> n;
  cum[0]=0;
  for (int i=1;i<=n;i++) {
    cin >> ar[i].first;
    ar[i].second=i;
  }
  cin >> k;
  sort(ar+1, ar+n+1);
  for (int i=1;i<=n;i++)
    cum[i] = cum[i-1] + ar[i].first;
  
  int l=1,r=2;
  ll sum=0;
  for (;r<=k;r++) {
    sum += (ar[r].first*(r-l) - (cum[r-1] - cum[l-1]));
  }
  ll ans=sum;
  ll start=1,end=k;
  for (;r<=n;r++) {
    sum -= cum[r-1] - cum[l] - (ar[l].first * (r-l-1));
    l++;
    sum += ar[r].first*(r-l) - (cum[r-1] - cum[l-1]);
    if (sum<ans) {
      ans = sum;
      start=l;
      end=r;
    }
  }
  for (int i=start;i<=end;i++) {
    cout << ar[i].second << ' ';
  }
}
