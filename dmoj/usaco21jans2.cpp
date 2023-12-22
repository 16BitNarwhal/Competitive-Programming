#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, q, a, b, pre[MM], suf[MM];
string s; stack<char> st;

int main() {
    cin >> n >> q >> s;

    for (int i=0; i<n; i++) {
        while (!st.empty() && s[i] < st.top()) st.pop();
        if (st.empty() || s[i] > st.top()) { st.push(s[i]); pre[i]++; }
        pre[i+1] = pre[i]; 
    } 

    while(!st.empty()) st.pop();
    
    for (int i=n-1;i>=0;i--) {
        suf[i] = suf[i+1];
        while (!st.empty() && s[i] < st.top()) st.pop();
        if (st.empty() || s[i] > st.top()) { st.push(s[i]); suf[i]++; } 
    }

    while(q--) {
        cin >> a >> b; a--; b--;
        cout << (a==0?0:pre[a-1]) + (b==n-1?0:suf[b+1]) <<'\n';
    }
}