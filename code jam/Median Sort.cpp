#include <bits/stdc++.h>
using namespace std;
const int MM = 51;
int t,n,q,ar[MM],lar[MM],mar[MM],rar[MM],lptr,mptr,rptr;
int Q(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << '\n';
    int ret;cin>>ret;return ret;
} 
void msort(int l, int r, bool rdiv=0) { // use r-1 and r
    if (r-l<=1) return;
    lptr = mptr = rptr = 1;
    int a = ar[r-1], b = ar[r];
    if (rdiv) a = ar[l], b = ar[r];
    // cout << "----------\n";
    // cout << l << ' ' << r << ' ' << a << ' ' << b << '\n';
    // for (int i=1;i<=n;i++) cout<<ar[i]<<' '; cout << '\n';
    for (int i=l+rdiv;i<r-1+rdiv;i++) {
        int x = Q(ar[i], a, b);
        if (x==-1) exit(0);
        if (x==a)
            lar[lptr++] = ar[i];
        else if (x==b) 
            rar[rptr++] = ar[i];
        else
            mar[mptr++] = ar[i];
    }
    // cout << lptr << ' '<< mptr << ' ' << rptr << '\n';
    for (int i=1;i<lptr;i++) 
        ar[i+l-1] = lar[i]; 
    for (int i=1;i<mptr;i++) 
        ar[i+l+lptr-1] = mar[i];
    for (int i=1;i<rptr;i++)
        ar[i+l+lptr+mptr-1] = rar[i];
    ar[l+lptr-1] = a, ar[l+lptr+mptr-1] = b;
    // for (int i=1;i<=n;i++) cout<<ar[i]<<' '; cout << '\n';
    // cout << "----------------\n";
    msort(l, l+lptr-1);
    msort(l+lptr, l+lptr+mptr-1);
    msort(l+lptr+mptr-1, r, 1);
}
int main() {
    cin>>t>>n>>q;
    while(t--){
        for (int i=1;i<=n;i++) ar[i]=i;
        msort(1,n);
        // for (int i=1;i<lptr;i++) cout<<lar[i]<<' '; cout << '\n';
        // for (int i=1;i<mptr;i++) cout<<mar[i]<<' '; cout << '\n';
        // for (int i=1;i<rptr;i++) cout<<rar[i]<<' '; cout << '\n';        
        for (int i=1;i<=n;i++) cout<<ar[i]<<' ';
        cout << '\n';
        int correct;cin>>correct;
        if(!correct) exit(0);
    }
}