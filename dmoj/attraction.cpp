#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int T, N, A, B;
int main() { 
    cin >> T;
    while (T--) {
        cin >> N >> A >> B ;vector<int> p(A);
        for (int i=0;i<A;i++) cin>>p[i];
        sort(p.begin(), p.end());
        // <value, state>
        priority_queue<pi> q;
        if (p[0] > 1) q.push({p[0]-1, 0}); // 0 is endpoint (left)
        if (p.back() < N) q.push({N - p.back(), 0}); // right endpoint
        for (int i=1;i<A;i++) {
            int gap = p[i] - p[i-1] - 1;
            if (gap == 0) continue;
            if (gap%2 == 0) q.push({gap/2, 2}); // 2 is even 1st attractor
            else q.push({(gap+1)/2, 3}); // 3 is odd 1st attractor
        }
        int ans = 0, val = 0, state = 0;
        while (!q.empty() && B>0) {
            tie(val, state) = q.top(); q.pop();
            if (val < 0) continue;
            ans += val; B--;
            if (state == 2) q.push({val, 0}); // even 2nd
            if (state == 3 && val >= 2) q.push({val-2, 1}); // odd 2nd
            if (state == 1) q.push({1, 0}); // odd 3rd
        }
        cout << ans << '\n';
    }
}
