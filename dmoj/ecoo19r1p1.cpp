#include <bits/stdc++.h>
using namespace std;
int N,M,D,event[1001];
void solve() {
    memset(event, 0, sizeof event);
    cin>>N>>M>>D;
    for (int i=0;i<M;i++) {
        int x;cin>>x;
        event[x]++;
    }
    int shirts=N,ans=0;
    for (int i=1;i<=D;i++) {
        if (shirts==0) { 
            ans++;
            shirts=N;
        }
        N += event[i];
        shirts += event[i];
        shirts--;
    }
    cout<<ans<<'\n';
}
int main() {
    int t=10;
    while(t--) solve();
}