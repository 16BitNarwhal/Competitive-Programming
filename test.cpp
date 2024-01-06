#include "bits/stdc++.h"
using namespace std;
int main() {
    // loop through all combinations of 1s and 0s size n
    int n;cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;
    vector<int> best1, best2;
    int mn=1e9;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            vector<int> b1, b2;
            if (i&(1<<j)) {
                b1.push_back(a[j]);
            } else {
                b2.push_back(a[j]);
            }
            int cnt=0;
            for (int k=0;k<b1.size();k++) {
                cnt += (b1[k] > b1[k-1]);
            }
            for (int k=0;k<b2.size();k++) {
                cnt += (b2[k] > b2[k-1]);
            }
            if (cnt < mn) {
                mn = cnt;
                best1 = b1;
                best2 = b2;
            }
        }
    } 
    cout << mn << '\n';
    for (int x:best1) cout << x << ' ';
    for (int x:best2) cout << x << ' ';
    cout << '\n';
    return 0;
}
