#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int t,n,c,ar[MM],ans[MM],r[MM];
int rsort() {
    int res=0;
    for (int i=1;i<n;i++) {
        int j=i;
        for (int k=i;k<=n;k++) {
            if (ar[k] < ar[j])
                j = k;
        }
        reverse(ar+i, ar+j+1); 
        res += j-i+1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (int tc=1;tc<=t;tc++) {
        cin>>n>>c;
        cout << "Case #"<<tc<<": ";
        if (c<n-1) { cout<<"IMPOSSIBLE\n"; continue; }
        int tmp = c;
        for (int i=1;i<n;i++) {
            int d = min(tmp-(n-i-1), n-i+1);
            tmp -= d;
            r[i] = d + i - 1; // reverse from i to r[i] 
        }
        memset(ar, 0, sizeof ar);
        for (int i=1;i<n;i++) {
            int x = r[i];
            for (int j=i-1;j>0;j--) {
                if (x >= j && x <= r[j])
                    x = r[j] - (x - j);
            }
            ar[x] = i;
        }
        for (int i=1;i<=n;i++) {
            if (!ar[i]) ar[i]=n;
            ans[i] = ar[i];
        }
        if (rsort()==c) 
            for (int i=1;i<=n;i++) cout << ans[i] << ' ';
        else 
            cout << "IMPOSSIBLE";
        cout << '\n';
    }
}