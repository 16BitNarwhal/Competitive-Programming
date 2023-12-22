#include <bits/stdc++.h>
using namespace std;
bool isint(char c) { return (c>='0' && c<='9'); }
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while (t--) {
        string s;cin>>s;
        if (s[0]=='R' && s.find('C')!=string::npos && isint(s[1])) {
            int r=0,c=0;
            int i=1;
            for (;i<s.length();i++) {
                if (!isint(s[i])) break;
                r*=10;
                r+=(int)(s[i]-'0');
            }
            i++;
            for (;i<s.length();i++) {
                c*=10;
                c+=(int)(s[i]-'0');
            }
            string res=""; 
            while (c) {
                if (c%26==0) res = 'Z'+ res, c-=26;
                else res = (char)('A'+(c%26)-1) + res;
                c/=26;
            }
            cout << res << r << '\n';
        } else {
            int r=0,c=0;
            int i=0;
            for (;i<s.length();i++) {
                if (isint(s[i])) break;
                c*=26;
                c+=(int)(s[i]-'A'+1);
            }
            for (;i<s.length();i++) {
                r*=10;
                r+=(int)(s[i]-'0');
            }
            cout<<"R"<<r<<"C"<<c<<'\n'; 
        }
        
    }
}