#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+2;
int n, r[MM], c[MM]; bool g[MM][MM];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        string s;cin>>s;
        for (int j=0;j<n;j++) g[i][j]=(s[j]=='L');
    }
    int total=0;
    for (int i=1;i<n;i++) {
        g[i][0] ^= g[0][0];
        for (int j=1;j<n;j++) {
            g[i][j] ^= g[i][0] ^ g[0][j];
            r[i] += g[i][j], c[j] += g[i][j], total += g[i][j];
        }
    }
    if (total==(n-1)*(n-1)) cout<<"1 1\n";
    else if (total==n-1) {
        for (int i=1;i<n;i++) 
            if(r[i]==n-1) { cout<<i+1<<" 1\n"; return 0; }
        for (int i=1;i<n;i++) 
            if(c[i]==n-1) { cout<<"1 "<<i+1<<'\n'; return 0; }
    } else if (total==1) {
        for (int i=1;i<n;i++) {
            for (int j=1;j<n;j++)
                if (g[i][j]) { cout<<i+1<<' '<<j+1<<'\n'; return 0; }
        }
    } else {
        cout << "-1\n";
    }
}