#include <bits/stdc++.h>
using namespace std;
#define x first
#define idx second
typedef long long ll;
const int MM = 2e5+2;
pair<int,int> a[MM];
int tt, n;
bool check(int m) {
    ll sum=0;
    for (int i=1;i<=m;i++) sum+=a[i].x;
    for (int i=m+1;i<=n;i++) {
        if (sum>=a[i].x) sum+=a[i].x;
        else return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>tt;
    while(tt--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i].x; a[i].idx=i;
        }
        sort(a+1,a+n+1);
        int l=1,r=n,m;
        while (l<r) {
            m=(l+r)/2;
            if (check(m)) r=m;
            else l=m+1;
        } 
        vector<int> ans;
        for (int i=l;i<=n;i++) ans.push_back(a[i].idx);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i:ans) cout << i << ' ';
        cout << '\n';
    }
}