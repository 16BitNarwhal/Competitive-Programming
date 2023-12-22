#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int X, Y;
string x[MM][2], y[MM][2];
int main() {
  cin >> X;
  for (int i=0;i<X;i++) 
    cin >> x[i][0] >> x[i][1];
  cin >> Y;
  for (int i=0;i<Y;i++)
    cin >> y[i][0] >> y[i][1];
  int ans=0;
  int N;cin>>N;
  map<string, int> mp;
  for (int i=0;i<N;i++) {
    string a, b, c;
    cin >> a >> b >> c;
    mp[a] = mp[b] = mp[c] = i;
  }
  for (int i=0;i<X;i++) {
    if (mp[x[i][0]] != mp[x[i][1]]) ans++;
  }
  for (int i=0;i<Y;i++) {
    if (mp[y[i][0]] == mp[y[i][1]]) ans++;
  }
  cout << ans << '\n';
}