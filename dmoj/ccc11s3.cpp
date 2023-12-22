#include <bits/stdc++.h>
using namespace std;
int t, m, sz, x, y;
bool res;
int pow(int a, int b) { return (b==0?1:(b&1?a:1)*pow(a*a,b>>1)); }

void rec(int curx, int cury) { 
    sz /= 5; if (sz==0) return;
    if (x>=sz+curx && x<2*sz+curx) {
        if (y<sz+cury) { res=1; return; }
        if (y<2*sz+cury) { rec(sz+curx, sz+cury); }        
    } else if (x>=2*sz+curx && x<3*sz+curx) {
        if (y<2*sz+cury) { res=1; return; }
        if (y<3*sz+cury) { rec(2*sz+curx, 2*sz+cury); }
    } else if (x>=3*sz+curx && x<4*sz+curx) {
        if (y<sz+cury) { res=1; return; }
        if (y<2*sz+cury) { rec(3*sz+curx, sz+cury); }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> x >> y; res=0;
        sz = pow(5, m);
        rec(0, 0);
        cout << (res?"crystal":"empty") << '\n';
    }
}