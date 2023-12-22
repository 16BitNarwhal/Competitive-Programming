#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;cin>>N;
    vector<int> odd, even;
    for (int i=0;i<N;i++) {
        int x;cin>>x;
        if (x&1) odd.push_back(x);
        else even.push_back(x);
    }
    for (int i:odd)cout<<i<<' ';
    for (int i:even)cout<<i<<' ';
    cout << '\n';
}

int main() {
    int t;cin>>t;
    while(t--) solve();
}