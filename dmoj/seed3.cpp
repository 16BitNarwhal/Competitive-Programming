#include <bits/stdc++.h>
using namespace std;
int a[(int)1e5+5];

int main() {
    int I,N,J;cin>>I>>N>>J;
    for(int i=0;i<J;i++) {
        int l,r,k;cin>>l>>r>>k;
        a[l]+=k;
        a[r+1]-=k;
    }
    for(int i=1;i<=I;i++) 
        a[i] += a[i-1];
    int ans=0;
    for(int i=1;i<=I;i++)
        ans += (a[i]<N);
    cout<<ans<<'\n';
}