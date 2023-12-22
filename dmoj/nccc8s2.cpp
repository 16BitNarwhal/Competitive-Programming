#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
string s;
unordered_map<char,int> cnt;
int main() {
    cin >> s;
    for (char c:s) cnt[c]++;
    long long res=1;
    for (auto i:cnt) res = 1LL*(i.second+1)*res%mod;
    cout << res << '\n';
}