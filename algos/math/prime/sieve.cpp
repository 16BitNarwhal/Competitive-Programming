// sieve's algorithm
// all primes up until n
// store the primes in an array/vector
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

ve<ull> primes;
void sieve(int n) {
    ve<bool> a(n+1, 1);
    for(ull i=2;i*i<=n;i++)
        if(a[i])
            for(ull j=i*2;j<=n;j+=i)
                a[j]=0;
    for(ull i=2;i<=n;i++)
        if(a[i]) primes.push_back(i);
}

int main() {
    int n;cin>>n;
    sieve(n);
    for(int i:primes) cout<<i<<" ";
    return 0;
}