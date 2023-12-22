#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int N, M, ar[MM];
int fun(int i) {
    if (i==0) return -1;
    if (ar[i]==-1) return ar[i]=i-1; 
    return ar[i]=fun(ar[i]);
}
int main() {
    memset(ar, -1, sizeof ar);
    cin >> N >> M;
    int ans=0; bool flag=1;
    for (int i=0;i<M;i++) {
        int x;cin>>x;
        if (flag && fun(x)>=0) ans++;
        else flag = 0;
    }
    cout << ans;

}