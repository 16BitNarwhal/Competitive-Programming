#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+10;
long long h[MM], b[MM];

int main() {
    int n;cin>>n;
    if (n<0) {
        cout << "0\n";
        return 0;
    }
    for (int i=1;i<=n+1;i++) cin>>h[i]; 
    for (int i=1;i<=n;i++) cin>>b[i];
    long long res=0;
    for (int i=1;i<=n;i++) {
        res += b[i]*(h[i]+h[i+1]);
    }
    // (using cout without fixed may print out scientifc notation)
    cout << fixed << res/2.0 << '\n';
    
}