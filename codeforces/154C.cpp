#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2, P = 31;
int n, m, ar[MM][2];
ll ha[MM], ppow[MM], ans=0; 
int main() {
    cin >> n >> m;
    ppow[0] = 1;
    for (int i=1;i<=n;i++) 
        ppow[i] = ppow[i-1] * P;
    
    for (int i=0;i<m;i++) {
        cin >> ar[i][0] >> ar[i][1];
        ha[ar[i][0]] += ppow[ar[i][1]];
        ha[ar[i][1]] += ppow[ar[i][0]];
    }
    for (int i=0;i<m;i++)
        ans += ha[ar[i][0]] + ppow[ar[i][0]] == ha[ar[i][1]] + ppow[ar[i][1]];
    sort(ha+1, ha+n+1);
    int c=0;
    for (int i=1;i<=n;i+=c) {
        c=0;
        while (i+c<=n && ha[i]==ha[i+c]) c++;
        ans += 1LL*c*(c-1)/2;
    }
    cout << ans;
}