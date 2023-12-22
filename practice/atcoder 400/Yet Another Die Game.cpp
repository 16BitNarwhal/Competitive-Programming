// https://atcoder.jp/contests/arc068/tasks/arc068_a
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main() {
    ll x, moves;
    cin>>x;
    moves = x/11;
    x -= moves*11;
    moves *= 2;
    if (x > 6) moves += 2;
    else if (x > 0) moves += 1;
    cout<<moves<<"\n";
}