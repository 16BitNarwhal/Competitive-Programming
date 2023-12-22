#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, Q;
long long freq[MM];
int main() {
    memset(freq, 0, sizeof freq);
    cin>>N>>Q;
    for (int i=0;i<N;i++) {
        int x;cin>>x;
        freq[x]++;
    }
    while(Q--) {
        int op, x; cin>>op>>x;
        if (op==1) {
            freq[x/2] += freq[x];
            freq[(x+1)/2] += freq[x];
            freq[x] = 0;
        } else {
            cout << freq[x] << '\n';
        }        
    }
}