/*
the first smaller element that precedes the
element in the array. It is possible that no such element exists, in which case the
algorithm should report this
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> a(n),res(n);
    for(auto &i:a) cin>>i;
    // use stack to maintain 'prev less than' elements
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++) {
        while(a[i]<=a[s.top()]) s.pop();
        res[i] = s.top();
        s.push(i);
    }
    for(auto i:res) cout<<i<<" ";
}