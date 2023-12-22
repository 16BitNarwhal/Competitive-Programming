#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int N, M, K, C[MM], T[MM], cnt[MM], processed[MM];
bool find(int x) {
    if (processed[x]>-1) return processed[x];
    memset(cnt, 0, sizeof cnt);
    int i=0, j=0;
    for (;i<M&&j<N;i++) { // loop troughs
        while (i<M && C[j]-K<=T[i] && T[i]<=C[j] && cnt[i]<x) // loop cows
            cnt[i]++, j++;  
    } 
    return processed[x]=(j==N);
}
int main() {
    memset(processed, -1, sizeof processed);
    cin >> N >> M >> K;
    for (int i=0;i<N;i++) cin>>C[i];
    for (int i=0;i<M;i++) cin>>T[i];
    sort(C, C+N);
    sort(T, T+M);
    int l=1,r=N;
    while (l<r) { 
        int m = (l+r)/2;
        if (find(m)) r=m;
        else l=m+1;
    }
    if (find(l)) cout << l << '\n';
    else cout << "-1\n";
}