#include <bits/stdc++.h>
using namespace std;

int a[(int)1e6+5];
int main() {
    int n;cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        if(i) a[i] = x+a[i-1];
        else a[i] = x;
    }
    int q;cin>>q;
    for(int i=0,l,r;i<q;i++) {
        cin>>l>>r;
        cout<<a[r]-(l==0?0:a[l-1])<<'\n';
    }    
}