/*
2sum but with 3 numbers
*/
#include <bits/stdc++.h>
using namespace std;

int main() { 
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    sort(a.begin(),a.end());
    bool flag=0;
    int i,j,k;
    for(k=0;k<n;k++) {
        i=k+1,j=n-1;
        while(i<j && a[i]+a[j]+a[k]!=x) {
            if(a[i]+a[j]+a[k]<x) i++;
            else j--;
        }
        if(a[i]+a[j]+a[k]!=x) continue;
        else {
            flag=1;break;
        }
    }
    if(flag) 
        cout<<a[i]+a[j]+a[k]<<" "<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";
    else cout<<"no\n";
}