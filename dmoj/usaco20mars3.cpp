#include <bits/stdc++.h>
using namespace std;
const int MM=1e5+2;
typedef pair<int,int> pi;
#define x first
#define y second
int n, mn[MM], mx[MM];
pi ar[MM]; 
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> ar[i].x >> ar[i].y;
  }
  sort(ar, ar+n);
  mn[0] = ar[0].y;
  for (int i=1;i<n;i++) 
    mn[i] = min(mn[i-1], ar[i].y);
  mx[n-1] = ar[n-1].y;
  for (int i=n-2;i>=0;i--)
    mx[i] = max(mx[i+1], ar[i].y);
  int ans=1;
  for (int i=0;i<n-1;i++) {
    if (mn[i] > mx[i+1]) ans++;
  }
  cout << ans << '\n';
}