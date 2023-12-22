#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 96*11, limit = 95*10*499;
int T,M,N,ans,ar[MM],pre[MM];
void solve(int tc) {
    cin >> M; N=0;
    for (int i=0;i<M;i++) {
        int a, b;cin>>a>>b;
        while (b--) {
            ar[N] = a;
            pre[N] = a + (N>0?pre[N-1]:0); 
            N++;
        }
    }
    ans = 0;
    for (int i=N-1;i>=0;i--) {
        ll prod = ar[i];
        if (pre[N-1] - pre[i] + (i>0?pre[i-1]:0) == prod) {
            ans = prod;
            goto q;
        }
        for (int j=i+1;j<N;j++) {
            prod *= ar[j];
            if (prod > limit) break;
            if (pre[N-1] - pre[j] + (i>0?pre[i-1]:0) == prod) {
                ans = prod;
                goto q;
            }
        }
    }
    q:;
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}
int main() {
    cin >> T;
    for (int tc=1;tc<=T;tc++) { 
        solve(tc);
    }
}