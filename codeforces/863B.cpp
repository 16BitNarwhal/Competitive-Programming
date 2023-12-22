#include <bits/stdc++.h>
using namespace std;
int N, ar[102];
int calc(int a, int b) {
    int ret=0;
    for (int i=0;i<N;i++) {
        if (i==a || i==b) continue;
        ret += ar[i+1] - ar[i];
        i++;
    }
    return ret;
}
int main() {
    cin>>N; N*=2;
    for (int i=0;i<N;i++) cin>>ar[i];
    sort(ar,ar+N); 
    int ans=1e9;
    for (int i=0;i<N;i+=2) {
        for (int j=i+1;j<N;j++) {
            if ((j-i)&1) ans = min(ans, calc(i,j));
        }
    }
    cout << ans;
}