#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;

int n, a[MM][4], res;
int main () {
    cin>>n;
    res = 0;
    for(int i=0;i<n;i++) for(int j=0;j<4;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i][0] < a[j][2] && a[i][2] > a[j][0] &&
                a[i][1] < a[j][3] && a[i][3] > a[j][1]) res++;
        }
    }
    cout << res;

}