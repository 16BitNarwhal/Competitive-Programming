#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int ans=0;
    bool flag=0;
    for (int i=0;i<n;i++) {
        if (a[i]==b[i]) {
            if (flag) {
                ans++; flag=0;
            }
        } else {
            flag = 1;
        }
    }
    cout << ans << '\n';
}