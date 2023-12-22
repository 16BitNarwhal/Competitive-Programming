#include <bits/stdc++.h>
using namespace std;

int a[101],b[101];
int main() {
    int q, n;cin>>q>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    if(q==1) sort(a, a+n);
    else sort(a, a+n, greater<int>());
    sort(b, b+n);
    int ans=0;
    for(int i=0;i<n;i++) ans+=max(a[i],b[i]);
    cout<<ans<<'\n';    
}