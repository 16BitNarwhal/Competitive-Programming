#include <bits/stdc++.h>
using namespace std;

bool check(int g[4][4]) {
    bool res = 1;
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            if(g[i][j] == g[i][j+1])
                res = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            if(g[i][j] == g[i+1][j])
                res = 0;
    return res;
}

int main() {
    int t_ = 5;
    while(t_--) {
        int g[4][4], cnt[16];
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>g[i][j];
        for(int i=0;i<16;i++) cnt[i] = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) {
                if(g[i][j]==0) cnt[0]++;
                else cnt[(int)log2(g[i][j])]++;
            }
        int res = (cnt[1]) ? 1 : 0;
        if(cnt[0] == 0 && check(g)) {
            for(int i=2;i<16;i++) {
                if(cnt[i]) res = i;
            }
        } else {
            for(int i=2;i<16;i++) {
                cnt[i] += cnt[i-1]/2;
                if(cnt[i]) res = i;
            }
        }
        if(res==0) cout<<"0\n";
        else cout<<pow(2,res)<<"\n";
    }
}