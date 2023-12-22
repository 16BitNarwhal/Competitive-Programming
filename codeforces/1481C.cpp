#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n,m,A[MM],B[MM],C[MM],ans[MM];
vector<int> vec[MM];
void solve() {
    cin >> n >> m;
    memset(ans, -1, sizeof ans);
    for (int i=0;i<n;i++) vec[i].clear();
    for (int i=0;i<n;i++) cin >> A[i];
    for (int i=0;i<n;i++) cin >> B[i]; 
    for (int i=0;i<m;i++) { cin >> C[i]; vec[C[i]].push_back(i); }
    int idx=-1;
    for (int i=0;i<n;i++) {
        if (C[m-1]==B[i]) {
            if (idx!=-1) {
                if (A[i]!=B[i]) 
                    idx=i;
            } else
                idx=i;
        }
    } 
    if (idx==-1) { cout << "no\n"; return; }
    for (int i=0;i<n;i++) {
        if (A[i]!=B[i]) {
            if (vec[B[i]].size()==0) { cout << "no\n"; return; }
            else {
                ans[vec[B[i]].back()] = i;
                vec[B[i]].pop_back();
            }
        }
    }
    cout << "yes\n";
    for (int i=0;i<m;i++) {
        if (ans[i]==-1) cout << idx+1 << ' ';
        else cout << ans[i]+1 <<' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) {
        solve();
    }
}

/*
1
10 5
7 3 2 3 7 9 4 2 7 9
9 9 2 3 4 9 4 3 3 9
9 9 3 4 3
*/