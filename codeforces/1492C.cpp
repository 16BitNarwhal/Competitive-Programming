#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
string s,t;
int n,m,mn[MM],mx[MM];
int main() {
    cin >> n >> m >> s >> t;
    int j=0;
    for (int i=0;i<m;i++) {
        while (t[i]!=s[j]) j++;
        mn[i] = j;
        j++;
    }
    j = n-1;
    for (int i=m-1;i>=0;i--) {
        while (t[i]!=s[j]) j--;
        mx[i] = j;
        j--;
    }
    int ans=0;
    for (int i=0;i<m-1;i++) {
        ans = max(ans, mx[i+1]-mn[i]);
    }
    cout << ans;
}