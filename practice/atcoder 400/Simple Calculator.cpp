// https://atcoder.jp/contests/agc008/tasks/agc008_a
#include <bits/stdc++.h>
using namespace std;

int f(int x, int y) {
    if(x<=y) return y-x;
    else return 2+x-y;
}
int main() {
    int x,y;cin>>x>>y;
    int ans = f(x,y);
    ans = min(ans, f(-x,y)+1);
    ans = min(ans, f(x,-y)+1);
    ans = min(ans, f(-x,-y)+2);
    cout<<ans<<"\n";
}