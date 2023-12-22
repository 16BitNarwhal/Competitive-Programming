#include <bits/stdc++.h>
using namespace std;
int K,N,sum[2001],val[2001]; 
int main() {
    cin >> K >> N;
    for (int i=1;i<=K;i++) {
        cin>> sum[i]; sum[i] += sum[i-1];
    }
    for (int i=1;i<=N;i++) cin>>val[i];
    set<int> init;
    for (int i=1;i<=K;i++)
        init.insert(val[1] - sum[i]);
    int ans=0;
    for (int v:init) {
        set<int> cur;
        for (int i=1;i<=K;i++)
            cur.insert(v + sum[i]);
        bool flag=1;
        for (int i=1;i<=N;i++) {
            if (!cur.count(val[i])) {
                flag=0; break;
            }
        }
        ans += flag;
    }
    cout << ans;
}