#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() { 
    int k,n;cin>>k;
    for(int i=0,x;i<k;i++) {
        cin>>x;
        a[x]=1;
    }
    for(int i=1;i<1000001;i++) a[i] += a[i-1];
    cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        cout<<x-a[x]<<'\n';
    }
}