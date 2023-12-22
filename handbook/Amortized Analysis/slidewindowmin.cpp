/*
At each window position, we want to calculate some information about the elements inside the window. In this section, we focus on the
problem of maintaining the sliding window minimum, which means that we
should report the smallest value inside each window.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;cin>>n>>k; 
    vector<int> a(n), res(n-k+1);
    for(auto &i:a)cin>>i;
    deque<int> dq; 
    for(int i=0;i<k;i++) {
        // cout<<i<<" ";
        // if(!dq.empty()) cout<<dq.front()<<" "<<dq.back();
        // cout<<"\n";
        while(!dq.empty() && a[i]<=a[dq.back()]) 
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k-1;i<n;i++) {
        if(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && a[i]<=a[dq.back()]) 
            dq.pop_back(); 
        dq.push_back(i);
        res[i-k+1] = dq.front();
    }
    for(auto i:res)cout<<i<<" ";
}