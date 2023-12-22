#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int n;
pair<int,int> inp[MM];
map<int, vector<int>> rowFreq, colFreq;

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    int x, y;
    cin >> x >> y;
    inp[i] = {x,y};
    rowFreq[x].push_back(y);
    colFreq[y].push_back(x);
  }
  for (auto &i : rowFreq) 
    sort(i.second.begin(), i.second.end());
  for (auto &i : colFreq) 
    sort(i.second.begin(), i.second.end());
  ll ans=0;
  for (int i=0;i<n;i++) {
    int x = inp[i].first, y = inp[i].second;
    ll left = lower_bound(rowFreq[x].begin(), rowFreq[x].end(), y) - rowFreq[x].begin();
    ll right = rowFreq[x].size() - left - 1;
    ll up = lower_bound(colFreq[y].begin(), colFreq[y].end(), x) - colFreq[y].begin();
    ll down = colFreq[y].size() - up - 1;
    ans += 2*left*right*up*down;
  }
  cout << ans << '\n';
}