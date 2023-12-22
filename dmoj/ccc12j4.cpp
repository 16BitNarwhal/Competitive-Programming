#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s;
    cin>>k>>s;
    for(int i=0;i<s.length();i++) {
        int sh = 3*i+3 + k;
        for(int j=0;j<26;j++) {
            char c = (j+sh)%26 + 'A';
            if(c == s[i]) {
                cout<<(char)(j+'A'); break;
            }
        }
    }
}