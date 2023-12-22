#include <bits/stdc++.h>
using namespace std;
int n, ar[4], ans;
void rec(int pos, int cur, int nxt) { 
    if (pos==3) {
        if (cur+nxt<=24) ans=max(ans,cur+nxt);
        if (cur-nxt<=24) ans=max(ans,cur-nxt);
        if (cur*nxt<=24) ans=max(ans,cur*nxt);
        if (nxt && cur%nxt==0 && cur/nxt<=24) ans=max(ans,cur/nxt);
        return;
    }
    pos++;
    rec(pos, cur+nxt, ar[pos]);
    rec(pos, cur-nxt, ar[pos]);
    rec(pos, cur*nxt, ar[pos]);
    if (nxt && cur%nxt==0) rec(pos, cur/nxt, ar[pos]);
    rec(pos, cur, nxt+ar[pos]);
    rec(pos, cur, nxt-ar[pos]);
    rec(pos, cur, nxt*ar[pos]);
    if (nxt%ar[pos]==0) rec(pos, cur, nxt/ar[pos]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        for (int i=0;i<4;i++) cin>>ar[i];
        ans = 0;
        do {
            rec(1, ar[0], ar[1]);
        } while(next_permutation(ar, ar+4));
        cout << ans << '\n';
    }
}