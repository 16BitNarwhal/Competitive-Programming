#include <bits/stdc++.h>

using namespace std;

int a[51];
int main() {
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        bool can=false;
        for (int i=0;i<n-1;i++) {
            if (a[i]!=a[i+1]) {
                can=true;
                break;
            }
        }
        if (can) {
            cout << "YES\n";
            cout << "R" << "B";
            for (int i=2;i<n;i++) cout << "R";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}