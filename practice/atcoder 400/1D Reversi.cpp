// https://atcoder.jp/contests/abc047/tasks/arc063_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<s.size()-1;i++)
        if(s[i] != s[i+1]) ans++;
    cout<<ans<<"\n";
}