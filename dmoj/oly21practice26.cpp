#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
struct pt { int x1, y1, x2, y2; } a[MM];
int N;
int main() {
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        a[i].x2 += a[i].x1, a[i].y2 += a[i].y1;
    }
    int p, q;cin>>p>>q;
    for (int i=N-1;i>=0;i--) {
        if (p >= a[i].x1 && p <= a[i].x2 && q >= a[i].y1 && q <= a[i].y2) {
            cout << i+1 << '\n'; return 0;
        }
    }
    cout << "-1\n";
}