// legendre's formuula
// largest x such that p^x divides n!
// returns an integer
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

int legendre(int n, int p) {
    int x=0;
    while(n) {
        n/=p;
        x+=n;
    }
    return x;
}

int main() {
    int n;cin>>n;
    return 0;
}