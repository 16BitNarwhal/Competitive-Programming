// https://atcoder.jp/contests/abc051/tasks/abc051_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,s;cin>>k>>s;
    int ans=0;
    for(int x=0;x<=k;x++) {
        for(int y=0;y<=k;y++) {
            int z = s-x-y;
            ans += (0<=z && z<=k);
        }
    }
    cout<<ans<<"\n";    
}