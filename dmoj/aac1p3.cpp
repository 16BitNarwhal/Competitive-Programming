#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;cin>>N>>X;
    if ((N&1) != (X&1)) { cout << "-1\n"; return 0; }
    int i=0;
    for (;i<X;i++) {
        if (i==N-1) cout<<"0";
        else cout << "0 ";
    }
    for (;i<N;i++) {
        if (i==N-1) cout<<"1";
        else cout << "1 "; 
        i++;
        if (i==N) break;
        if (i==N-1) cout<<"0";
        else cout << "0 ";
    }
    cout << '\n';
}