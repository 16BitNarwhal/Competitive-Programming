#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, p[2*MM], con[MM];
int fd(int d, int p[]) { return d==p[d]? p[d]:p[d] = fd(p[d], p); } 
int main() {
    cin >> N >> M; int cnt = N;
    for (int i=1;i<=N;i++)
        p[i]=i, con[i]=i, p[i+N]=i+N; 
    for (int i=1,u,v;i<=M;i++) {
        char op; cin>>op>>u>>v;
        int su = fd(u, p), sv = fd(v, p), du = fd(u+N, p), dv = fd(v+N, p);
        if (op=='S') {
            if (su==dv || sv==du) {
                cout << "0\n"; return 0;
            }
            p[su] = sv, p[du] = dv;
        } else {
            if (su==sv || du==dv) {
                cout << "0\n"; return 0;
            }
            p[su] = dv, p[du] = sv;
        }
        if (fd(u, con) != fd(v, con)) {
            cnt--; con[fd(u, con)] = fd(v, con);
        }
    }
    cout<<1;
    for (int i=0;i<cnt;i++) cout<<0;
}