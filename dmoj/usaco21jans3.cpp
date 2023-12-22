#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
int n, a[MM][MM], row, col;

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) {
        int sumr[2] = {0,0}, sumc[2] = {0,0};
        for(int j=1;j<=n;j++) { 
            sumr[j&1] += a[i][j];
            sumc[j&1] += a[j][i];
        }
        row += max(sumr[0], sumr[1]);
        col += max(sumc[0], sumc[1]);
    }
    cout << max(row, col) << '\n';
}