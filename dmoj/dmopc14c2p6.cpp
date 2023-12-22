// https://dmoj.ca/problem/dmopc14c2p6
#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5+1;
int ar[mxn];
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    int Q;cin>>Q;
    while(Q--) {
        int a,b,q,sum=0;
        cin>>a>>b>>q;
        for(int i=a;i<=b;i++)
            if(ar[i] >= q) sum+=ar[i];

        cout<<sum<<endl;
    }
    return 0;
}