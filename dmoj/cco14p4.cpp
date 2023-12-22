#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[100005];

bool cmp(const pair<int,int> l, const pair<int,int> r) {
    return l.second < r.second;
}
int main() {
    int n,p;cin>>n>>p;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    p--;
    int fuel = a[p].first, planets = 0;
    for(int i=0;i<n;i++) if(i==p) a[i].first=a[i].second=0;
    sort(a, a + n, cmp);
    for(int i=0;i<n;i++) {
        if(a[i].first - a[i].second < 0) continue;
        if(fuel < a[i].second) continue; 
        fuel += a[i].first - a[i].second;
        planets++;
    }
    cout<<fuel<<'\n'<<planets<<'\n';
}