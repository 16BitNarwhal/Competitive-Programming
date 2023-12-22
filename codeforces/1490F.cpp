#include <bits/stdc++.h>
using namespace std;
int T, N; 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {  
        cin >> N;
        map<int,int> cnt, cntCnt;
        for (int i=0,x;i<N;i++) {
            cin>>x;
            cnt[x]++;
        }
        for (auto it : cnt) cntCnt[it.second]++;
        int ans=N, cntR=cnt.size();
        for (auto it : cntCnt) {
            ans = min(ans, N - cntR*it.first); 
            cntR -= it.second;
        }
        cout << ans << '\n';
    }
}