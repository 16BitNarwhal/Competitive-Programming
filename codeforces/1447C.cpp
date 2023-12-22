#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int,int> w[(int)(2e5+2)];
int main() {
  int t;cin>>t;
  while (t--) {
    int n;
    ll W;
    cin>>n>>W;
    for (int i=0;i<n;i++) {
      cin >> w[i].first;
      w[i].second = i+1;
    }
    sort(w,w+n,greater<pair<int,int>>());
    ll sum=0;
    vector<int> v;
    for (int i=0;i<n;i++) {
      if (sum + w[i].first <= W) {
        sum += w[i].first;
        v.push_back(w[i].second);
      }
    }
    if (sum < (W+1)/2) {
      cout << "-1\n"; continue;
    } 
    cout << v.size() << '\n';
    for (int i : v) {
      cout<<i<<" ";
    }
    cout << '\n';
  } 
  
}