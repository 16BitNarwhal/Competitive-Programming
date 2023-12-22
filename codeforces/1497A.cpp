#include <bits/stdc++.h>
using namespace std;
int a[101], cnt[101];
int main() {
    int T;cin>>T;
    while(T--) {
        memset(cnt, 0, sizeof cnt);
        int n;cin>>n;
        for (int i=0;i<n;i++) {
            cin>>a[i]; cnt[a[i]]++;
        }
        for (int i=0;i<=100;i++) {
            if (cnt[i]) {
                cnt[i]--;
                cout << i << ' ';
            }
        }
        for (int i=0;i<=100;i++) {
            while (cnt[i]--) cout<<i<<' ';
        }
        cout << '\n';
    }
}