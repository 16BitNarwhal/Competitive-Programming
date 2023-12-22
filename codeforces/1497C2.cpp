#include <bits/stdc++.h>
using namespace std;
void func(int n) {
    if (n%2==1) cout<<"1 "<<n/2<<' '<<n/2<<'\n';
    else if (n%4==0) cout<<n/2<<' '<<n/4<<' '<<n/4<<'\n';
    else if (n%2==0) cout<<n/2-1<<' '<<n/2-1<<' '<<2<<'\n';
}
int main() {
    int T;cin>>T;
    while (T--) {
        int n, k; cin>>n>>k;
        for (int i=0;i<k-3;i++) cout<<"1 ";
        func(n-(k-3));
    }
}