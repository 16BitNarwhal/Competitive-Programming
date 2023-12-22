// // Method 1 of editorial
// #include <bits/stdc++.h>
// using namespace std;
// const int MM = 1e6+2;
// struct query { int l, r, x, id; bool ans; } in[MM];
// bool cmp(query a, query b) { return a.r < b.r; }
// bool reorder(query a, query b) { return a.id < b.id; }
// int N, Q, X, ar[MM], val[MM];
// void compute(int i) { 
//     for (int a=1;a*a<in[i].x;a++) {
//         if (in[i].x % a == 0) {
//             int b = in[i].x / a;
//             if (ar[a] < in[i].l || ar[b] < in[i].l) {
//                 continue;
//             }
//             in[i].ans = 1;
//             return;
//         }
//     }
//     in[i].ans = 0;
// }
// int main() {
//     memset(ar, 0, sizeof ar);
//     cin >> N >> Q;
//     for (int i=1;i<=N;i++) cin>>val[i];
//     for (int i=0;i<Q;i++) {
//         cin >> in[i].l >> in[i].r >> in[i].x;
//         in[i].id = i;
//     }
//     sort(in, in+Q, cmp);
//     int j=0;
//     for (int i=0;i<Q;i++) { 
//         for (;j<=in[i].r;j++) {
//             ar[val[j]] = j;
//         } 
//         compute(i);
//     } 
//     sort(in, in+Q, reorder);
//     for (int i=0;i<Q;i++) {
//         if (in[i].ans) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }

// Method 2 of editorial (slower but in my opinion, simpler)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int N, Q, id[MM];
// vec[val][pos]
vector<int> vec[MM];
int main() {
    cin >> N >> Q;
    for (int i=1;i<=N;i++) {
        int v;cin>>v;
        vec[v].push_back(i);
    }
    for (int i=0;i<Q;i++) {
        int l, r, x; cin >> l >> r >> x;
        for (int a=1;a*a<x;a++) {
            if (x % a != 0) continue;
            int b = x / a;
            // first occurence of a and b after position l
            int pa = lower_bound(vec[a].begin(), vec[a].end(), l) - vec[a].begin();
            int pb = lower_bound(vec[b].begin(), vec[b].end(), l) - vec[b].begin();
            if (pa < vec[a].size() && vec[a][pa] <= r &&
                pb < vec[b].size() && vec[b][pb] <= r) {
                    cout << "YES\n";
                    goto q;
                }
        }
        cout << "NO\n";
        q:;
    }
}