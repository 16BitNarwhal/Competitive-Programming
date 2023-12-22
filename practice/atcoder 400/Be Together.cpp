// https://atcoder.jp/contests/arc059/tasks/arc059_a
#include <bits/stdc++.h>
using namespace std;

int ar[111];

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    int ans = INT_MAX;
    for(int i=-100;i<=100;i++) {
        int sum=0;
        for(int j=0;j<n;j++) {
            int d = ar[j]-i;
            d *= d;
            sum += d;
        }
        ans = min(ans, sum);
    }
    cout<<ans<<"\n";
}