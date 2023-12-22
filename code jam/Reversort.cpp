#include <bits/stdc++.h>
using namespace std;
const int MM = 101;
int t,n,ar[MM];
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
        cin>>n;
        for (int i=1;i<=n;i++) cin>>ar[i];
        cout << "Case #" << tc << ": " << rsort() << '\n';
    }
}