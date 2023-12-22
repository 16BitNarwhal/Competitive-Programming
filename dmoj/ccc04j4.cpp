#include <bits/stdc++.h>
using namespace std;

int main() {
    string key;getline(cin,key);
    string msg;getline(cin,msg);
    int i=0, n=key.length();
    for(char c:msg) {
        if(c<'A' || c>'Z') continue;
        cout<<(char)(((int)(c-'A')+(int)(key[i]-'A'))%26+'A');
        i = (i+1)%n;
    }
}