// https://dmoj.ca/problem/ac19p1
#include <iostream>

using namespace std;

void solve() {
    long long n, a, b, c, ar[3];
    cin>>n>>a>>b>>c;
    if(c<=n) {
        n -= c;
        ar[2] = c;
    } else {
        ar[2] = n;
        n = 0;
    }
    if(b<=n) {
        n -= b;
        ar[1] = b;
    } else {
        ar[1] = n;
        n = 0;
    }
    if(a<=n) {
        n -= a;
        ar[0] = a;
    } else {
        ar[0] = n;
        n = 0;
    }
    if(n>0) {
        cout<<-1<<endl;
        return;
    }
    for(int i:ar) cout<<i<<" ";
    cout<<endl;
}
int main() {
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}