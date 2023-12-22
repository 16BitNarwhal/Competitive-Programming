#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;
int main() {
    unordered_map<int,int> mp;
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[x]++;
    }
    priority_queue<pi> q;
    for(auto i:mp) q.push({i.S, i.F});
    pi a = q.top();
    q.pop();
    pi b = q.top();
    int res = 0;
    while(!q.empty() && q.top().F == b.F) {
        b = q.top();
        q.pop();
        res = max(res, abs(a.S - b.S));
    }
    cout<<res;
}