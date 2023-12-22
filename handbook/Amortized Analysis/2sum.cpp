/*
 given an array of n numbers and a
target sum x, find two array values such that their sum is x, 
or report that no such values exist.
*/
#include <bits/stdc++.h>
using namespace std;

int main() { 
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    while(i<j && a[i]+a[j]!=x) {
        if(a[i]+a[j]<x) i++;
        else j--;
    }
    if(i==j) cout<<"no\n";
    else cout<<a[i]+a[j]<<" "<<a[i]<<" "<<a[j]<<"\n"; 
}