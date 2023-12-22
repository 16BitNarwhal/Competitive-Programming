#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+2, INF = 0x3f3f3f3f;
int N,M,nxt[MM][26];
string S,T;
int main() {
    cin>>N>>M>>S>>T;
    memset(nxt, 0x3f, sizeof nxt);
    for (int i=0;i<N;i++) {
        int c = S[i]-'a';
        if (nxt[N][c]==INF) nxt[N][c]=i;
    }
    for (int i=N-1;i>=0;i--) {
        int c = S[i]-'a';
        for (int j=0;j<26;j++)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][c] = i;
    }
    long long ans = -1;
    for (int i=0;i<M;i++) {
        int t=nxt[(ans+1)%N][(int)(T[i]-'a')];
        int add = t - (ans%N);
        if (t==INF) {
            cout << "-1\n"; return 0;
        }
        if (add<=0) add+=N;
        ans += add;
    }
    cout << ans+1 << '\n';
}