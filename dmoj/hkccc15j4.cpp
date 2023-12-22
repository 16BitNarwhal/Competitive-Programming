#include <bits/stdc++.h>
using namespace std;
#define l first
#define r second
typedef pair<int,int> pi;
const int MM = 1e5+2;
pi ar[MM];
vector<pi> res;
int main() {
    int L, N; cin >> L >> N;
    for (int i=1;i<=N;i++) cin>>ar[i].first>>ar[i].second; 
    ar[0] = {0,0};
    ar[N+1] = {L,L};
    sort(ar, ar+N+2);
    pi prv, cur=ar[0];
    int ans=0;
    for (int i=0;i<=N+1;) {
        prv = cur; cur = ar[i]; 
        while (i<=N+1 && cur.r>=ar[i].l) {
            cur.r = max(cur.r, ar[i].r);
            i++;
        } 
        ans = max(ans, cur.l - prv.r);
    }
    cout << ans;
}