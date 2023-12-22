#include <bits/stdc++.h>
using namespace std;

int main() {
    string buf;
    unsigned int l=1, r=2e9;
    while (l<=r) {
        int m = (l+r)/2;
        cout << m << '\n';
        cin >> buf; 
        if (buf=="SINKS") l=m+1;
        else if (buf=="FLOATS") r=m-1;
        else break;
    }
}