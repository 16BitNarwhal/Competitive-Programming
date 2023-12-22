#include <bits/stdc++.h> 
using namespace std; 
  
typedef long long int ll; 

int gcd(int a, int b) { 
    return (b == 0) ? a : gcd(b, a%b);
} 
\
ll lcm(int a, int b) {
    return (1LL*a*b)/gcd(a,b);
}

int main() {
    ll res = 1;
    for(int i=1;i<=20;i++) {
        res = lcm(res, i);
    }
    cout<<res<<"\n";
    return 0; 
}