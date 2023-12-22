#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string,int> mp;
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        mp[s]++;
    }
    int res=0;
    for(auto i:mp) 
        res += (i.second==1) ? 1 : 0;
    cout<<res<<'\n';
}