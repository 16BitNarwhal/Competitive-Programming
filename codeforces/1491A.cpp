#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, q, a[MM], cnt[2]; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cnt[0]=cnt[1]=0;
    cin >> n >> q;
    for (int i=1;i<=n;i++) { 
        cin>>a[i]; 
        cnt[a[i]]++;
    }
    while (q--) {
        int op;cin>>op;
        if (op==1) {
            int x;cin>>x;
            cnt[a[x]]--;
            a[x] ^= 1;
            cnt[a[x]]++;
        } else { 
            int k;cin>>k;
            if (cnt[1]>=k) cout << "1\n";
            else cout << "0\n";
        }
    } 
    
}