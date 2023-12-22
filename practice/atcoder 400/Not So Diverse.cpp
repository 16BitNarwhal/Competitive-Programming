// https://atcoder.jp/contests/arc086/tasks/arc086_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;cin>>n>>k;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[x]++;
    }
    vector<int> ar;
    for(auto &i : mp)
        ar.push_back(i.second);
    sort(ar.rbegin(), ar.rend());
    long long sum=0;
    for (int i=k;i<ar.size();i++)
        sum += ar[i];
    cout<<sum<<"\n";
}