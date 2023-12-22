#include <bits/stdc++.h>
using namespace std;
const int MM = 22;

int n,m,a[MM][MM];
int ltr[MM][MM],rtl[MM][MM],ttb[MM][MM],btt[MM][MM]; 
//  left-right, right-left, top-bottom, bottom-top

int main() {
    int q=5;
    while(q--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m ;j++)
            cin>>a[i][j];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ltr[i][j] = max((j==0) ? 0:ltr[i][j-1], a[i][j]);
                ttb[i][j] = max((i==0) ? 0:ttb[i-1][j], a[i][j]);
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                rtl[i][j] = max((j==m-1) ? 0:rtl[i][j+1], a[i][j]);
                btt[i][j] = max((i==n-1) ? 0:btt[i+1][j], a[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans += max(min(min(ltr[i][j],rtl[i][j]),min(ttb[i][j],btt[i][j]))-a[i][j],0);
            }
        }
        std::cout<<ans<<"\n";
    }
}
/*
10 10
55 89 17 36 19 75 77 40 57 87

46 16 24 52 62 65 38 97 90 93
14 67 47 59 7 66 71 24 64 20
20 37 18 78 23 1 56 7 98 16
98 45 13 16 69 5 52 50 7 44
79 58 50 38 55 72 46 57 78 5

3 52 44 74 83 58 78 95 36 15
43 78 16 49 77 24 70 27 28 19
20 59 55 68 85 46 13 39 40 38
92 71 9 24 12 48 45 31 61 18
*/
// out 802