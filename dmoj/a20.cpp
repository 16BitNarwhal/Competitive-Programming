#include <bits/stdc++.h>
using namespace std;

string hex2bin(string hex) {
    string bin="";
    for(char c : hex) {
        int x;
        if(c>='A') x = (int)(c-'A')+10;
        else x = (int)(c-'0');
        string s;
        while(x) {
            s = to_string(x%2) + s;
            x /= 2;
        }
        stringstream ss;
        ss << setw(4) << setfill('0') << s;
        bin += ss.str();
    }
    return bin;
}

string bin2hex(string bin) {
    string hex="";
    for(int i=0;i<(int)bin.length();i+=4) {
        string s = bin.substr(i,4);
        int mult = 1, x = 0;
        for(int j=s.length()-1;j>=0;j--) {
            x += mult*(int)(s[j]-'0');
            mult *= 2;
        }
        if(x>=10) hex += (char)(x-10)+'A';
        else hex += to_string(x);
    }
    return hex;
}

int main() {
    int t_;cin>>t_;
    while(t_--) {
        string s;cin>>s;
        string bin = hex2bin(s);
        if(bin[bin.length()-21]=='1') {
            bin[bin.length()-21]='0';
            cout<<bin2hex(bin)<<" ";
        }
        cout<<s<<"\n";
    }
}