#include <bits/stdc++.h>
using namespace std;
string ar[8];
bool col[8], diag1[16], diag2[16];
int cnt=0;
// col[x] || diag1[x+y] || diag2[n-1-x+y]
void search(int y) { 
    if(y==8) { cnt++; return; }
    for (int x=0;x<8;x++) {
        if (ar[y][x]=='*' || col[x] || diag1[x+y] || diag2[8-1-x+y]) continue;
        col[x] = diag1[x+y] = diag2[8-1-x+y] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[8-1-x+y] = 0;
    }
}
int main() {
    for (int i=0;i<8;i++) cin>>ar[i];
    search(0);
    cout << cnt;
}