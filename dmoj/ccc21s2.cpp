#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e6+2;
bool r[MM], c[MM];
int n, m, k;
int main() {
    cin >> n >> m >> k;
    for (int i=0;i<k;i++) {
        char op; int x; cin >> op >> x;
        if (op=='R') {
            r[x] = !r[x];
        } else {
            c[x] = !c[x];
        }
    }
    int cntC=0,cntR=0; 
    for (int i=1;i<=n;i++) if(r[i]) cntR++;
    for (int i=1;i<=m;i++) if(c[i]) cntC++; 
    cout << (1LL*cntR*m) + (1LL*cntC*n) - (1LL*2*cntR*cntC) << '\n';
}