#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, K, a[MM], cnt[MM], dist=0;
ll ans=0;
int main() {
    memset(cnt, 0, sizeof cnt);
    cin >> N >> K;
    for (int i=1;i<=N;i++) cin>>a[i];
    cnt[a[1]]++, dist++;
    int l=1,r=1;
    while (r<=N) {
        if (dist >= K) {
            ans += N - r + 1;
            cnt[a[l]]--;
            if (cnt[a[l]]==0) dist--;
            l++;
        } else {
            r++;
            if (cnt[a[r]]==0) dist++;
            cnt[a[r]]++;
        }
    }
    cout << ans << '\n';
}