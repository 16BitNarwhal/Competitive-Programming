// https://atcoder.jp/contests/abc047/tasks/abc047_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int l=0,r,b=0,t,n;
    cin>>r>>t>>n;
    for(int i=0;i<n;i++) {
        int x,y,a;
        cin>>x>>y>>a;
        if(a==1) {
            l = max(l,x);
        } else if(a==2) {
            r = min(r,x);
        } else if(a==3) {
            b = max(b,y);
        } else if(a==4) {
            t = min(t,y);
        }
    }
    if(l>=r || b>=t) 
        cout<<"0\n";
    else
        cout<<(r-l)*(t-b)<<"\n";
    return 0;
}