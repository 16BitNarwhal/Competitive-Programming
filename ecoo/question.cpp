#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int N, M, K;
pair<int,int> ar[MM];
int main() {
    memset(ar, -1, sizeof ar);
    cin >> N >> M>> K;
    for (int i=0,a,b,c;i<K;i++) {
        cin >> a >> b >> c;
        if (c > ar[b].second) {
            ar[b] = {a,c};
        }
    }
    for (int i=1;i<=N;i++) {
        cout << ar[i].first << ' ';
    }
}