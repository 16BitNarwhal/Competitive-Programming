#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;cin>>s;
    a[0] = (s[0]=='G');
    for(int i=1;i<=s.length();i++) {
        a[i] = (s[i]=='G') + a[i-1];
    }
    int n;cin>>n;
    for(int i=0,l,r;i<n;i++) {
        cin>>l>>r;
        if(l==0) cout<<a[r]<<'\n';
        else cout<<a[r]-a[l-1]<<'\n';
    }
}