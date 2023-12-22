#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 1e8;
bool pr[n];

void sieve() {
    memset(pr, 1, n);
    int x=0;
    for(int i=2;i*i<=n;i++) {
        if(pr[i]) 
            for(int j=i*i;j<=n;j+=i)
                pr[j] = 0;
    }
}

int main() {
    sieve();
    int x=0;
    for(int i=2;i<=n;i++) {
        if(pr[i]) {
            x++;
            if(x>1e4) {
                cout<<i<<"\n";
                return 0;
            }
        }
    }
    cout<<"bruh "<<x;
}