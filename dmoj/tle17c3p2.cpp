#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
int main() {
    int n,m;cin>>n>>m;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        mp[x] = i;
    }
    long long res=1;
    int p;cin>>p;
    for(int i=1,x;i<m;i++) {
        cin>>x;
        res += abs(mp[x]-mp[p]);
        p = x;
    }
    cout<<res<<'\n';

    
}