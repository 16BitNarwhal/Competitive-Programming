#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;cin>>a>>b>>c;
    if (a+b>=c) cout<<a+b;
    else if (a+(2*b)>=c) cout<<a+(2*b);
    else if (a+(3*b)>=c) cout<<a+(3*b);
    else cout << "Who knows...";
}