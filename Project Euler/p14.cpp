#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;

int main() {
    int res = 1, mx = 1;
    for(int i=1;i<=N;i++) {
        int c=1;
        long long n=i;
        while(n>1) {
            if(!(n&1)) n/=2;
            else n = n*3+1;
            c++;
        }
        if(c> mx) {
            res = i;
            mx = c;
        }
    }
    cout<<res<<"\n";
}