#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        string s;
        getline(cin,s);
        if(s=="0") return 0;
        if(s.length()==1) {
            cout<<s<<'\n';continue;
        }
        reverse(s.begin(),s.end());
        stack<string> st;
        string ans="";
        for(auto c:s) {
            if(c==' ') continue;
            if(c=='+' || c=='-') {
                ans = st.top() + " ";
                st.pop();
                ans += st.top() + " " + c;
                st.pop();
                st.push(ans);
            } else 
                st.push(string(1,c));
        }
        cout<<ans<<'\n';
    }
    
}