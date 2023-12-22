#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> mp;
int main() {
  int n,x;
  cin>>n>>x;
  ll ans=0;
  for (int i=0;i<n;i++) {
    int a;cin>>a;
    if (mp[a]) 
      ans += mp[a]; 
    mp[a^x]++;
  }  
  cout << ans << '\n';
}