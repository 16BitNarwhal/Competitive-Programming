#include <bits/stdc++.h>
using namespace std;
int N, ar[8];
set<multiset<int>> ans;
void check(int sum, int b, int c) {
    int a = sum-b-c;
    set<int> s = {0,a,b,c,a+b,a+c,b+c,a+b+c};
    for (int i=0;i<=N;i++) {
        if (!s.count(ar[i])) return;
    }
    ans.insert({a,b,c});
}
void test(int sum) {
    set<int> candidates;
    for (int i=0;i<=N;i++) {
        if (ar[i]>sum) return;
        if (ar[i]==0 || ar[i]==sum) continue;
        candidates.insert(min(ar[i], sum-ar[i]));
    }
    int a = *begin(candidates);
    int b = *next(begin(candidates));
    check(sum,a,b);
    check(sum,a,sum-b);
}
void solve() {
    cin >> N;
    for (int i=0;i<N;i++) cin>>ar[i];
    ar[N] = 0;
    ans.clear();
    for (int i=0;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            test(ar[i]+ar[j]); // sum of 2 numbers in array must be a+b+c
        }
    }
    cout << ans.size() << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}