#include <bits/stdc++.h>
using namespace std;

int n, peaks[100001];
int cnt[100001];

bool check(int stride) {
    int prev=0;
    for (int i=stride-1;i<n;i+=stride) {
        assert(cnt[i] >= prev);
        if (cnt[i] == prev) return false;
        prev = cnt[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) cin >> peaks[i];
    for (int i=1;i<n-1;i++) {
        if (peaks[i] > peaks[i-1] && peaks[i] > peaks[i+1]) 
            cnt[i] = 1; 
    }
    for (int i=1;i<n;i++) cnt[i] += cnt[i-1];
    
    if (cnt[n-1]==0) {
        cout << "0\n";
        return 0;
    }

    vector<int> div;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            div.push_back(i);
            if (n/i != i) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());

    int l=0, r=div.size()-1;
    int min_stride=-1;
    while (l<=r) {
        int m = (l+r)/2;
        if (check(div[m])) {
            r = m-1;
            min_stride = div[m];
        } else {
            l = m+1;
        }
    }
    
    cout << n / min_stride << '\n';
}