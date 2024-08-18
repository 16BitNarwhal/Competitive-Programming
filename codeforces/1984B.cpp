#include <bits/stdc++.h>

using namespace std;

int main() {
    int _; cin >> _;
    while (_--) {
        long long n; cin >> n;
        bool ans=true;
        while (n) {
            long long d = n%10;
            if (n==d && d!=1) {
                ans=false; break;
            }
            if (d==9) {
                ans=false; break;
            }
            n/=10;
            n--;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}