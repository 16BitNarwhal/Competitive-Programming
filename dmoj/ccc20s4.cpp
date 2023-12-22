#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;

int fun(string s) {
    int n = s.length(), cntA=0, cntB=0;
    for (int i=0;i<n;i++) {
        if (s[i]=='A') cntA++;
        else if (s[i]=='B') cntB++;
    }
    int res = 1e9;
    for (int i=0;i<n;i++) {
        int BinA = 0, AinB = 0, notA = 0, notB = 0;
        int l = i, r = (i+cntA)%n;
        for (int j=0;j<cntA;j++) {
            int k = (l+j)%n;
            if (s[k] == 'B') BinA++;
            if (s[k] != 'A') notA++; 
        }
        
        l = (l+cntA)%n, r = (r+cntB)%n;
        for (int j=0;j<cntB;j++) {
            int k = (l+j)%n;
            if (s[k] == 'A') AinB++;
            if (s[k] != 'B') notB++; 
        }
        res = min(res, notA + notB - min(AinB, BinA));
    }
    return res;
} 

int main() {
    string s; cin>>s;
    string perm = "ABC";
    int ans = 1e9;
    do {
        string t;
        for (char c : s) 
            t += perm[(int)c-'A'];
        ans = min(ans, fun(t));
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans;
}