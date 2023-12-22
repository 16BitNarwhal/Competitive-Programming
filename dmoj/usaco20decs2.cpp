#include <bits/stdc++.h>
using namespace std;
const int MM = 2501;
struct pt { int x,y; };
bool ycmp(pt a, pt b) { return a.y < b.y; }
bool xcmp(pt a, pt b) { return a.x < b.x; }
int N, sum[MM][MM]; pt P[MM];
int rsum(pt a, pt b) {
    a.x--; a.y--;
    int ret=sum[b.x][b.y];
    if (a.x>=0) ret -= sum[a.x][b.y];
    if (a.y>=0) ret -= sum[b.x][a.y];
    if (a.x>=0 && a.y>=0) ret += sum[a.x][a.y];
    return ret;
}
int main() {
    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> P[i].x >> P[i].y;
    sort(P, P+N, xcmp);
    for (int i=0;i<N;i++) P[i].x=i;
    sort(P, P+N, ycmp);
    for (int i=0;i<N;i++) P[i].y=i;
    for (int i=0;i<N;i++) sum[P[i].x][P[i].y]=1;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i) sum[i][j] += sum[i-1][j];
            if (j) sum[i][j] += sum[i][j-1];
            if (i&&j) sum[i][j] -= sum[i-1][j-1];
        }
    } 
    long long ans=0;
    for (int i=0;i<N;i++) {
        for (int j=i;j<N;j++) {
            int x1 = min(P[i].x, P[j].x);
            int x2 = max(P[i].x, P[j].x);
            ans += rsum({0,i}, {x1,j}) * rsum({x2,i}, {N-1,j});
        }
    }
    cout << ans + 1;
}