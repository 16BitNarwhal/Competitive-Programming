#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l;
    cin>>n>>l;
    string s;
    cin.ignore();
    getline(cin,s);
    for(char c:s)
        cout<<((c==' ') ? ' ' : (char)(((int)(c-'a')+l)%26+'a'));
}