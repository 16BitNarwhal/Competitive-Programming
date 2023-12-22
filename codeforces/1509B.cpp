#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    int N;cin>>N;
    int T=0, M=0;
    cin >> s; 
    for (int i=0;i<N;i++) { 
        if (s[i]=='M') M++;
        else T++;
        if (T < M) {
            cout << "NO\n"; return;
        }
    }
    T = M = 0;
    for (int i=N-1;i>=0;i--) {
        if (s[i]=='M') M++;
        else T++;
        if (T < M) { 
            cout << "NO\n"; return;
        }
    }
    if (T != M*2) cout << "NO\n"; 
    else cout << "YES\n";
}

int main() {
    int t;cin>>t;
    while(t--) solve();
}