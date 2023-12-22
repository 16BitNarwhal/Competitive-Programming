#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
void solve() {
    int n;cin>>n;
    string ar[3];
    cin >> ar[0] >> ar[1] >> ar[2];
    pair<int,int> ways[] = {{0,1}, {0,2}, {1,2}, {1,0}, {2,0}, {2,1}};
    for (auto p : ways) {
        deque<char> a;
        for (char c:ar[p.F]) a.push_back(c);
        deque<char> b;
        for (char c:ar[p.S]) b.push_back(c);
        string res="";
        while (!a.empty()) {
            res += a.front();
            if (a.front()==b.front()) b.pop_front();
            a.pop_front();
        }
        while (!b.empty()) {
            res += b.front();
            b.pop_front();
        }
        if (res.size() > 3*n) continue;
        cout << res << '\n';
        return;
    }
    while(1) {
        // time limit exceed
    }
}

int main() {
    int t;cin>>t;
    while(t--) solve();
}