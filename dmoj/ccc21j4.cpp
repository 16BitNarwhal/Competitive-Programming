#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;cin>>s;
    int n=s.length(), L=0, M=0;
    for (int i=0;i<n;i++) {
        L += s[i]=='L';
        M += s[i]=='M';
    }
    int cntML=0, cntSL=0, cntLM=0, cntSM=0;
    for (int i=0;i<L;i++) {
        cntML += s[i]=='M';
        cntSL += s[i]=='S'; 
    }
    for (int i=L;i<L+M;i++) {
        cntLM += s[i]=='L';
        cntSM += s[i]=='S';
    }
    cout << max(cntML,cntLM)+cntSL+cntSM << '\n';
}