/*
consider a problem where we are given an array of n positive
integers and a target sum x, and we want to find a subarray whose sum is x or
report that there is no such subarray
*/
#include <bits/stdc++.h>
using namespace std;

int main() { 
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    for(int i=1;i<n;i++) a[i]+=a[i-1];
    int i=0,j=0;
    while(j<n && a[j]-a[i-1]!=x) {
        if(a[j]-a[i]<x) j++;
        else i++;
    }
    if(j==n) cout<<"no\n";
    else cout<<a[j]-a[i-1]<<" "<<i<<" "<<j<<"\n";
}