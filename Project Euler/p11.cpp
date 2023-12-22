#include <bits/stdc++.h>
using namespace std;
const int n=20;
int ar[n][n];

int main() {
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>ar[i][j];
    int mx=0;
    for(int i=0;i<n-4;i++) for(int j=0;j<n-4;j++) {
        int x=ar[i][j];
        for(int c=1;c<4;c++) 
            x *= ar[i+c][j+c];
        mx = max(mx, x);
        x=ar[i][j];
        for(int c=1;c<4;c++) 
            x *= ar[i+c][j];
        mx = max(mx, x);
        x=ar[i][j];
        for(int c=1;c<4;c++)
            x *= ar[i][j+c];
        mx = max(mx, x);
        x=ar[i][j+3];
        for(int c=1;c<4;c++) 
            x *= ar[i+c][j+3-c]; 
        mx = max(mx, x);
    }
    cout<<mx<<"\n";
}