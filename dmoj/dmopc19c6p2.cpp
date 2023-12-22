#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int a, b, res, cnt[MM];
vector<int> fac;

int main() {
    cin >> a >> b;
    int tmp = a;
    for (int i=2;i*i<=a;i++) {
        if (tmp%i==0) fac.push_back(i);
        while (tmp%i==0) {
            tmp /= i;
            cnt[i]++;
        }
    }
    if (tmp>1) {
        fac.push_back(tmp);
        cnt[tmp]++;
    }
    res = 1e9;
    for (int f : fac) {
        int div = f, cnt2 = 0;
        while (b/div>0) {
            cnt2 += b/div;
            div *= f;
        }
        res = min(res, cnt2/cnt[f]);
    }
    cout << res;
}