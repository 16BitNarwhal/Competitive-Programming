#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n;cin>>t;
    while(t--) {
        cin >> n;
        cout << (n==2 ? n : n-1) << '\n';
    }
}