#include <bits/stdc++.h>
using namespace std;

int w;
string s = "a";

int main() {
    cin>>w; 
    
    int j = 0;
    for(int i=0;i<w;i++) {
        cout<<s<<' ';
        int j=s.length()-1;
        while(j>=0 && s[j]=='z') {
            s[j]='a';
            j--;
        }
        if(j<0) s+='a';
        else s[j]++;
    }
}