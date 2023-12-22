#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e6;
bool pr[n];
void sieve() {
    memset(pr, 1, n);
    pr[0]=pr[1]=0;
    for(int i=2;i*i<n;i++) {
        if(pr[i]) 
            for(int j=i*i;j<n;j+=i)
                pr[j] = 0;
    }
}

int main() {
    sieve();
    ll sum = 0;
    for(int i=2;i<n;i++) {
        if(pr[i]) sum+=i;
    }
    cout<<sum<<"\n";
}