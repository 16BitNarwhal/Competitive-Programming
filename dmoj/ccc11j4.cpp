#include <bits/stdc++.h>
using namespace std;
const int MM = 405, N = 200;
int x, y, g[MM][MM]; bool flag=1;
void db(int x1, int y1, int x2, int y2) {
    for (int i=x1;i<=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            if(g[i][j])cout<<'o';
            else cout<<'.';
        }cout<<'\n';
    }
}
void fun(char dir, int len, bool print=0) {
    for (int i=0;i<len;i++) {
        switch(dir) {
            case 'l':
                x--;
                break;
            case 'r':
                x++;
                break;
            case 'd':
                y--;
                break;
            case 'u':
                y++;
                break;
        }
        if(g[x][y]) {
            // db(N-10, N-10, N+10, N+10);
            flag = 0;
        }
        g[x][y] = 1;
    }
    if (print) {
        if (flag) cout << x-N << ' ' << y-N << " safe\n";
        else cout << x-N << ' ' << y-N << " DANGER\n";

    } 
}
int main() {
    x=N, y=N;
    fun('d',3); 
    fun('r',3); 
    fun('d',2); 
    fun('r',2); 
    fun('u',2);
    fun('r',2); 
    fun('d',4);
    fun('l',8);
    fun('u',2);
    while (flag) {
        char dir;cin>>dir;
        int len;cin>>len;
        if (dir=='q') return 0;
        fun(dir, len, 1);
    }
    // db(N-10, N-10, N+10, N+10);
}