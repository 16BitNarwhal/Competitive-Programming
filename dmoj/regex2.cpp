// Also works for ccc98s1
#include <bits/stdc++.h>
using namespace std;

bool valid(char c) {
    return (tolower(c)>='a' && tolower(c)<='z') || (c>='0'&&c<='9');
}

int main() {
    int t;scanf("%d\n",&t);
    while(t--) {
        string s;
        getline(cin,s);
        for(int i=0;i<s.length();i++) {
            if(valid(s[i])) {
                int j=0;
                while(i+j<s.length() && valid(s[i+j]))
                    j++;
                if(j==4) {
                    for(int k=0;k<4;k++)
                        s[i+k]='*';
                }
                i+=j;
            }
        }
        cout<<s<<'\n';
    }
}