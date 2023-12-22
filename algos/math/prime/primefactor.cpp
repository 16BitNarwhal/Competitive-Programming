// prime factorization (gets all prime factors)
// time complexity O(sqrt(N))
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

ve<pair<int,int>> factors; // (base, exponent)
void factor(int n) {
    for(int i=2;i*i<=n;i++)
        if(n%i==0) {
            int c=0;
            while(n%i==0) {
                c++;
                n/=i;
            }
            factors.push_back({i,c});
        }
    if(n>1) factors.push_back({n,1});
}

int main() {
    int n;cin>>n;
    factor(n);
    for(auto i:factors) {
        cout<<i.first<<"^"<<i.second<<endl;
    }
    return 0;
}