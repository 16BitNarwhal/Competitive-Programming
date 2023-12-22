#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;cin>>n>>k;
    string s; 
    getline(cin,s); getline(cin, s); 
    s+=' ';
    string cur="", word="";
    int cnt=0;
    for (int i=0;i<s.length();i++) {  
        if (s[i]==' ') {
            if (cnt+word.length() > k) {
                cout<<'\n';
                cnt = 0;
            } else if (cnt>0) {
                cout<<' ';
            }
            cout << word;
            cnt += word.length();
            word = "";
        } else {
            word += s[i];
        }
    } 
    cout << '\n';
}