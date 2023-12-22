#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int ar[MM];
void solve() {
    int n;cin>>n;
    for (int i=1;i<=n;i++)
        cin >> ar[i];      
    if (ar[1] != ar[2]) {
        if (ar[2] == ar[3]) cout<<"1\n";
        else cout << "2\n";
        return;
    }
    for (int i=3;i<=n;i++) {
        if (ar[i] != ar[i-1]) {
            cout << i << '\n';
            return;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}