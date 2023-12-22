// https://atcoder.jp/contests/arc069/tasks/arc069_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;cin>>n>>m;
    ll x = min(n,m/2);
    x += (m - x*2) / 4;
    cout<<x<<"\n";
}