#include <bits/stdc++.h>
using namespace std;

int main() {
    string s,t;cin>>s>>t;
    int n=s.length(),m=t.length();
    for(int i=0;i<=n-m;i++) {
        string x = s.substr(i,m);
        x = x+x;
        if(x.find(t)!=string::npos) {
            cout<<"yes\n";
            return 0;
        }
    }
    cout<<"no\n";
}