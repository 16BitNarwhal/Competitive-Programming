#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cnt(3,0);
    string s; cin>>s;
    for (char c : s) {
        cnt[(int) (c-'a')]++;
    }
    if (abs(cnt[0] - cnt[1]) <= 1 && 
    abs(cnt[0] - cnt[2]) <= 1 && 
    abs(cnt[1] - cnt[2]) <= 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}