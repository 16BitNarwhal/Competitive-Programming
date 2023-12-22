// https://atcoder.jp/contests/abc082/tasks/arc087_a
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[x]++;
    }
    ll ans=0;
    for(auto &i : mp) {
        if(i.first < i.second)
            ans += i.second - i.first;
        else if(i.first > i.second)
            ans += i.second;
    }
    cout<<ans<<"\n";
}