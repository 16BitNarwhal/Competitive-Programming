#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int T, N, M, a[MM], cnt[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--) {
        int ans=0;
        memset(cnt, 0, sizeof cnt);
        cin>>N>>M; 
        for (int i=0;i<N;i++) {
            cin>>a[i]; a[i]%=M; 
            cnt[a[i]]++;
        }
        for (int i=1;i<(M+1)/2;i++) {
            if (cnt[i] || cnt[M-i]) {
                int tmp = min(cnt[M-i], cnt[i]);
                cnt[M-i] -= tmp, cnt[i] -= tmp;
                if (cnt[M-i]>0) cnt[M-i]--;
                if (cnt[i]>0) cnt[i]--; 
                ans++;
                ans += cnt[M-i] + cnt[i];
            }
        }
        ans += (cnt[0]>0);
        if (M%2==0) ans += (cnt[M/2]>0);
        cout << ans << '\n';
    }
}