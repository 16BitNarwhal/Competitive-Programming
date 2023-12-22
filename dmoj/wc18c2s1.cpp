#include <bits/stdc++.h>
using namespace std;

int l=0,r=1000000,t=1000000,b=0;
int stX, stY, n, m, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>stX>>stY>>n>>m>>c;
    for(int i=0,buf;i<n;i++) {
        cin>>buf;
        if(buf < stX) l = max(l,buf);
        else r = min(r, buf);
    }
    for(int i=0,buf;i<m;i++) {
        cin>>buf;
        if(buf < stY) b = max(b, buf);
        else t = min(t, buf);
    }
    for(int i=0,x,y;i<c;i++) {
        cin>>x>>y;
        if(l <= x && x <= r && b <= y && y <= t) cout<<"Y\n";
        else cout<<"N\n";
    }
}