#include <bits/stdc++.h>
using namespace std;

int a[25];
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<n;j++) cout<<a[j]<<' ';
    cout<<'\n';
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) 
            if(a[j]>a[j+1]) {
                swap(a[j],a[j+1]); 
                for(int j=0;j<n;j++) cout<<a[j]<<' ';
                cout<<'\n';
            }
    }
}