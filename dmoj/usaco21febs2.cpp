#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
int N, K, dist[MM], ptr=0;
set<int> s;
int main() {
    cin >> N >> K;
    for (int i=0,x;i<N;i++) {
        cin>>x; s.insert((x+11)/12);
    }
    int prev = 0;
    for (int i : s) { 
        // dist from previous time period to current time period
        dist[ptr++] = (i - prev - 1);
        prev = i;
    }
    sort(dist, dist+ptr, greater<int>()); 
    // portal to earliest period, then remove longest k-1 dists
    int ans = *s.rbegin(); 
    for (int i=0;i<min(K-1,ptr);i++)
        ans -= dist[i];
    cout << ans*12;
}