// find if n is prime
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

bool isPrime(int n) {
    if(n<=1) return 0;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) return 0;
    }
    return 1;
}

int main() {
    int n;cin>>n;
    if(isPrime(n)) cout<<"prime \n";
    else cout<<"not prime \n";
    return 0;
}