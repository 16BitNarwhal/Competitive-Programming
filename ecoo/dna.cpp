#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++) {
        cout << s[i];
        if (s[i]=='A' && s[i+1]!='A') 
            continue;
        if (s[i]!='A' && s[i+1]=='A') 
            continue;
        cout << ' ';
    }
}