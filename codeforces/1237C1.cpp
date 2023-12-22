#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
struct p { int x, y, z; } ar[MM];
bool used[MM];
int dis(p a, p b) {
  return abs(a.x-b.x) + abs(a.y-b.y) + abs(a.z-b.z);
}
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    cin >> ar[i].x >> ar[i].y >> ar[i].z;
  }
  for (int i=0;i<n;i++) {
    if (used[i]) continue;
    int k=-1;
    int best = 2e9;
    for (int j=i+1;j<n;j++) {
      if (used[j]) continue;
      if (dis(ar[i], ar[j]) < best) {
        best = dis(ar[i], ar[j]);
        k = j;
      }
    }
    used[i] = used[k] = 1;
    cout << i+1 << ' ' << k+1 << '\n';
  }
}