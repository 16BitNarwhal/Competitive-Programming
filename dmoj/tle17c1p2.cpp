#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;

int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        string s;int x;
        cin>>s>>x;
        mp[s]=x;
    }
    cin>>n;
    vector<pair<int,string>> a(n);
    for(auto &i:a) {
        string s;int x;
        cin>>s>>x;
        i.first = x;
        i.second = s;
    }
    sort(a.begin(),a.end());
    int i=0,sum=0,p=0;
    while(i<n && (a[i].first==p || a[i].first <= sum)) {
        sum += mp[a[i].second];
        p=a[i].first;
        i++;
    }
    cout<<i<<'\n';
}