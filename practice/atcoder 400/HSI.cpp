#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    int p = (1<<m), t = (m*1900) + (n-m)*100;
    cout<<t*p<<"\n";
}