#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int t, n, a[MM], dis[MM];
void process(int l, int r, int d) {  
    if(l==r) dis[l]=d;
    if(l>=r) return;
    int mx=0,mxpos=0;
    for (int i=l;i<=r;i++) 
        if (a[i]>mx) mx=a[i], mxpos=i;
    dis[mxpos] = d;
    process(l, mxpos-1, d+1);
    process(mxpos+1, r, d+1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i=0;i<n;i++) cin>>a[i];
        process(0, n-1, 0);
        for (int i=0;i<n;i++) cout<<dis[i]<<' ';
        cout << '\n';
    }
}