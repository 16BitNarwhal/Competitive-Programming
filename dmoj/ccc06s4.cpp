#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int N, op[MM][MM], id;
bool flag, flag2;

int main() {
    cin >> N;
    while(N) {
        for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) cin >> op[i][j];
        flag = 1;
        for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) for (int k=1;k<=N;k++) {
            if (op[i][op[j][k]]!=op[op[i][j]][k]) {
                flag=0; goto q;
            } 
        } 
        id = -1;
        for (int i=1;i<=N;i++) {
            for (int x=1;x<=N;x++) {
                if (op[x][i]!=x || op[i][x]!=x) break;
                if (x==N) id = i;
            }
        }
        if (id==-1) { flag=0; goto q; }
        for (int i=1;i<=N;i++) {
            flag2 = 0;
            for (int j=1;j<=N;j++) {
                if (op[i][j]==id && op[j][i]==id) {
                    flag2 = 1; break;
                }
            }
            if (!flag2) { flag=0; goto q; }
        }
        q:;
        cout << (flag?"yes":"no") << '\n';
        cin >> N;
    }
}