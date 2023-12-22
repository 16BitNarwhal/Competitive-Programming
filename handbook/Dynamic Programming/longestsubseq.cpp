/*
Our first problem is to find the longest increasing subsequence in an array
of n elements. This is a maximum-length sequence of array elements that goes
from left to right, and each element in the sequence is larger than the previous
element
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    vector<int> dp(n, 1);
    for(int i=0;i<n;i++) 
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) 
                dp[i] = max(dp[i], dp[j]+1);
    int mx=0;
    for(auto i:dp) mx=max(mx, i);
    cout<<mx<<"\n";
}