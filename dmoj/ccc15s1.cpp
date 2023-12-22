#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    int n;cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        if(x==0 && !s.empty()) s.pop();
        else s.push(x);
    }
    int sum=0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout<<sum<<'\n';
}