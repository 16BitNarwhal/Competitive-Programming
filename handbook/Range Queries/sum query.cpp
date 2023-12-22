/*
sum prefix 2D array
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n,m;cin>>n>>m;
    vector<vi> a(n+1, vi(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    int q;cin>>q;
    while(q--) {
        int i1,j1,i2,j2;
        cin>>i1>>j1>>i2>>j2;
        i1--; j1--;
        cout<< a[i2][j2] - a[i2][j1] - 
            a[i1][j2] + a[i1][j1] <<"\n";
        
    }
}