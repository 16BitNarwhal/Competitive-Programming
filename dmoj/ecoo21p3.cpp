#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int best[MM], prof[MM];
int main() {
    int N,M,K;
    cin >> N >> M >> K;
    memset(prof, -1, sizeof prof);
    memset(best, 0, sizeof best);
    for (int i=0;i<K;i++) {
        int a,b,c;cin>>a>>b>>c;
        if (c>best[b]) {
            best[b] = c;
            prof[b] = a;
        }
    }
    for (int i=1;i<=N;i++) {
        cout << prof[i] <<" ";
    }
}