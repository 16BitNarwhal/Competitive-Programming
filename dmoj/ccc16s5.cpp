#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, a[MM], tmp[MM];
ll t;

int main() {
    cin >> n >> t;
    string inp; cin >> inp;
    for (int i=0;i<n;i++) a[i] = (inp[i]=='1');
    for (int k=50;k>=0;k--) {
        if (t>>k&1) {
            int x = (1LL<<k)%n;
            for (int i=0;i<n;i++) 
                tmp[i] = a[((i-x)%n+n)%n] ^ a[(i+x)%n];
            for (int i=0;i<n;i++)
                a[i] = tmp[i];
        }
    }    
    for (int i=0;i<n;i++) cout<< a[i];
    cout << '\n';
}