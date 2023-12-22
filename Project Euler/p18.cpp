#include <bits/stdc++.h>
using namespace std;
const int n = 100;
int ar[n][n];

int main() {
    for(int i=0;i<n;i++) 
        for(int j=0;j<=i;j++) 
            cin>>ar[i][j];
    for(int i=1;i<n;i++) 
        for(int j=0;j<=i;j++) {
            if(j==0) ar[i][j] += ar[i-1][j];
            else ar[i][j] += max(ar[i-1][j], ar[i-1][j-1]);
        }
    int mx=0;
    for(int i=0;i<n;i++) {
        mx = max(mx, ar[n-1][i]);
    }
    cout<<mx<<"\n";
}