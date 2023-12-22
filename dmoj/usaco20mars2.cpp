#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;
int n, m, cnt=0, cow[MM], qry[MM][2], ans[MM];
void replace(int i, int pos) {
  if (cow[pos] == -1) {
    cow[pos] = i;
    cnt++;
  } else if (cow[pos] > i) {
    int prv = cow[pos];
    cow[pos] = i;
    replace(prv, qry[prv][1]);
  }

}
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> qry[i][0] >> qry[i][1];
  } 
  
  memset(cow, -1, sizeof cow);
  for (int i=n-1;i>=0;i--) {
    replace(i, qry[i][0]);
    ans[i] = cnt;
  }

  for (int i=0;i<n;i++) {
    cout << ans[i] << '\n';
  }
  
}