#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin>>s;
    for (int i=0;i<s.length();i++) {
        if (i==0) cout<<s[i];
        else if (s[i-1]=='A' && s[i]!='A') cout<<s[i];
        else if (s[i-1]!='A' && s[i]=='A') cout<<s[i];
        else cout<<' '<<s[i];
    }
}