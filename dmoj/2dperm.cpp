#include <bits/stdc++.h>
using namespace std;
const int MN = 25000010;
int cnt[MN];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cnt[i*j]++;
            cnt[n*m-(n-i+1)*(m-j+1)+2]--;
            cout<<n*m-(n-i+1)*(m-j+1)+2<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=1;i<=n*m;i++) cout<<cnt[i]<<" ";
    for(int i=2;i<=n*m;i++)
        cnt[i] += cnt[i-1];
    while(Q--) {
        int x;cin>>x;
        cout<<cnt[x]<<"\n";
    }

}
