#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    while(n--) {
        int x;cin>>x;
        int y = x;
        for(int i=2;i*i<=x;i++) {
            while(y%i==0) {
                cout<<i<<' ';
                y /= i;
            }
        }
        if(y>1)cout<<y;
        cout<<'\n';
    }
}