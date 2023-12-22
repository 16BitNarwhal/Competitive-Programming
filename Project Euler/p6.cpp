#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 1e2;
int main() {
    long long a=0,b=0;
    for(int i=1;i<=n;i++) {
        a += i*i;
        b += i;
    }
    cout<<b*b-a<<"\n";
}