#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        stack<int> a,b;
        int n;cin>>n;
        int x,nxt=1,res=0;
        for(int i=0;i<n;i++) {
            cin>>x;
            a.push(x);
        } 
        while(1) { 
            if(a.empty() && b.empty()) {
                res=1; break;
            }
            if(!a.empty() && a.top() == nxt) {
                nxt++;
                a.pop();
            } else if(!b.empty() && b.top() == nxt) {
                nxt++;
                b.pop();
            } else if(!a.empty() && a.top() != nxt) {
                b.push(a.top());
                a.pop();
            } else if(a.empty()) break;
        }
        cout<< (res==1 ? 'Y':'N') <<'\n';
    }
}