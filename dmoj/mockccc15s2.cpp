#include <bits/stdc++.h>
using namespace std;

int a[100001];
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        a[x]++;
    }
    int mx=0;
    for(int i=0;i<n;i++) 
        mx = max(mx,a[i]);
    cout<<mx<<'\n';
}