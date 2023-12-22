#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000002;

int n,a[MM],pre[MM],suf[MM];

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) pre[i] = max(i==0?0:pre[i-1], a[i]);
    for(int i=n-1;i>=0;i--) suf[i] = max(i==n-1?0:suf[i+1], a[i]);
    
    ll ans=0;
    for(int i=0;i<n;i++)
        ans += max(0, min(pre[i],suf[i])-a[i]);
    cout<<ans;
}