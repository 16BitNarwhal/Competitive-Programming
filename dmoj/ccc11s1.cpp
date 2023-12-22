#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s=0,t=0;
    cin>>n;
    cin.ignore();
    string buf;
    for(int i=0;i<n;i++) { 
        getline(cin,buf);
        for(char c:buf) {
            if(tolower(c) == 's') s++;
            else if(tolower(c) == 't') t++; 
        }
    }
    if(t>s) cout<<"English\n";
    else cout<<"French\n";

}