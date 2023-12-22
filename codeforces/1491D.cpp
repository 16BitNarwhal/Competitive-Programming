#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q;
void solve() {
    cin>>p>>q;
    if (p>q) { cout<<"no\n"; return; }
    int bits=0;
    for (int i=0;i<30;i++) {
        if ((p>>i)&1) bits++;
        if ((q>>i)&1) bits--;
        if (bits<0) { cout<<"no\n"; return; }
    }
    cout << "yes\n";
}

int main() {
    int t;cin>>t;
    while(t--) solve();
}
 